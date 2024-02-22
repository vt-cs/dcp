#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#define PORT_NUMBER 8181
#define SERVER_HELLO "HTTP/1.1 200 OK\r\nContent-Length: 13\r\nConnection: close\r\n\r\nHello, world!"


bool is_valid_ip_address (char *ip_address)
{
    // TODO: logic
    return true;
}

bool is_port_number_valid (int port_number)
{
    // TODO: logic
    return true;
}

int create_tcp_ipv4_socket (char *ip_address, int port_number)
{
    printf ("%s:: entry\n", __func__);
    if (is_valid_ip_address (ip_address) == false || is_port_number_valid (port_number) == false)
    {
        printf ("%s:: invalid args passed... exiting\n", __func__);
	return -1;
    }

    // success = valid socket fd
    // failure = -1
    int tcp_ipv4_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_ipv4_sock_fd < 0)
    {
        perror ("socket");
	return -1;
    }
    printf ("%s:: socket created: %d\n", __func__, tcp_ipv4_sock_fd);

    int socket_option = 1;
    int status = setsockopt (tcp_ipv4_sock_fd, SOL_SOCKET, SO_REUSEADDR, &socket_option, sizeof (socket_option));
    if (status < 0)
    {
        perror ("setsockopt");
    }

    struct sockaddr_in server_ipv4_addr;
    server_ipv4_addr.sin_family = AF_INET;
    server_ipv4_addr.sin_port = htons (port_number);

    // success = 1
    // failure = -1
    status = inet_pton (AF_INET, ip_address, &(server_ipv4_addr.sin_addr.s_addr));
    if (status < 0)
    {
        perror ("inet_pton");

	// clean up
	close (tcp_ipv4_sock_fd);
	return -1;
    }
    printf ("%s:: socket structure updated\n", __func__);

    // success = 0
    // failure = -1
    status = bind (tcp_ipv4_sock_fd, (struct sockaddr*) &server_ipv4_addr, sizeof (struct sockaddr_in));
    if (status < 0)
    {
        perror ("bind");

	// clean up
	close (tcp_ipv4_sock_fd);
	return -1;
    }
    printf ("%s:: socket bind success\n", __func__);
    printf ("%s:: returning socket fd:: %d\n", __func__, tcp_ipv4_sock_fd);

    return tcp_ipv4_sock_fd;
}

int main (int argc, char **argv)
{

    int server_sock_fd = 0;
    int port_number = 8181;
    char ipv4_address_server[INET_ADDRSTRLEN] = {0};

    memcpy (ipv4_address_server, "192.168.165.183", INET_ADDRSTRLEN);

    server_sock_fd = create_tcp_ipv4_socket(ipv4_address_server, port_number);
    if (server_sock_fd < 0)
    {
        printf ("%s:: error creating tcp ipv4 socket\n", __func__);
	exit (EXIT_FAILURE);
    }

    printf ("%s:: socket created: fd=%d\n", __func__, server_sock_fd);

    int ret_status = 0;
    ret_status = listen (server_sock_fd, 5);
    if (ret_status < 0)
    {
        perror ("listen");

	// clean up
	close (server_sock_fd);
	server_sock_fd = 0;

	exit (EXIT_FAILURE);
    }

    printf ("%s:: listening on: %s:%d\n", __func__, ipv4_address_server, port_number);

    int client_sockets[30];
    int max_client = 30;
    for (int i=0; i<max_client; ++i)
    {
        client_sockets[i] = 0;
    }

    while (true)
    {
        fd_set readfds;
        FD_ZERO (&readfds);

	FD_SET (server_sock_fd, &readfds);
	int max_sock_fd = server_sock_fd;

	for (int i=0; i<max_client; ++i)
	{
            int sock_fd = client_sockets[i];

	    if (sock_fd > 0)
	    {
                FD_SET (sock_fd, &readfds);
	    }

	    if (sock_fd > max_sock_fd)
	    {
                max_sock_fd = sock_fd;
	    }
	}

	int activity = select (max_sock_fd+1, &readfds, NULL, NULL, NULL);
	if (activity < 0)
	{
            perror ("select");
	}

	// if something happened on server_sock_fd, then it is a new connection
	if (FD_ISSET (server_sock_fd, &readfds))
	{
            socklen_t client_address_len = sizeof (struct sockaddr_in);
	    struct sockaddr_in client_address;
            int accept_sock_fd = accept (server_sock_fd, (struct sockaddr*) &client_address, &client_address_len);
	    if (accept_sock_fd < 0)
	    {
                perror ("accept");
	    }
	    printf ("connection accepted from:: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
	    send (accept_sock_fd, "hello from server", 18, 0);

	    // add new socket to our array
	    for (int i=0; i<max_client; ++i)
	    {
                // if position is empty
                if (client_sockets[i] == 0)
		{
                    client_sockets[i] = accept_sock_fd;
		    break;
		}
	    }
	}

	for (int i=0; i<max_client; ++i)
	{
            int sock_fd = client_sockets[i];
	    char read_buffer [1024] = {0};
	    struct sockaddr_in client_address;
	    socklen_t client_address_len = sizeof (struct sockaddr_in);
	    if (FD_ISSET (sock_fd, &readfds))
	    {
                // check if connection is closing
		int valread = 0;
                if ((valread = read(sock_fd, read_buffer, sizeof (read_buffer)-1)) == 0)
		{
                    getpeername (sock_fd, (struct sockaddr*) &client_address, (socklen_t*) &client_address_len);
                    printf ("host disconnected:: IP - %s, PORT - %d\n\n", inet_ntoa (client_address.sin_addr), ntohs (client_address.sin_port));

		    close (sock_fd);
		    client_sockets[i] = 0;
		}
		// else echo back the same message to client that came in
		else
		{
                    read_buffer [valread] = '\0';
                    send (sock_fd, read_buffer, strlen (read_buffer), 0);
		}
	    }
	}
    }

    // clean up
    printf ("cleaning up...\n");
    close (server_sock_fd);
    server_sock_fd = 0;

    return 0;
}
