#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#define PORT_NUMBER 8181


bool is_valid_ip_address (char *ip_address)
{
    // logic
    return true;
}

bool is_port_number_valid (int port_number)
{
    // logic
    return true;
}

int create_tcp_ipv4_socket (char *ip_address, int port_number)
{
    printf ("%s:: entry\n", __func__);
    if (is_valid_ip_address (ip_address) == false)
    {
        printf ("%s:: invalid ip address... exiting\n", __func__);
	return -1;
    }
    if (is_port_number_valid (port_number) == false)
    {
        printf ("%s:: invalid port number... exiting\n", __func__);
        return -1;
    }

    // success = valid socket fd
    // failure = -1
    int tcp_ipv4_listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_ipv4_listen_sock < 0)
    {
        printf ("%s:: error in creating socket... exiting\n", __func__);
        perror ("socket");
	return -1;
    }
    printf ("%s:: socket created\n", __func__);

    struct sockaddr_in server_ipv4_addr;
    server_ipv4_addr.sin_family = AF_INET;
    server_ipv4_addr.sin_port = htons (port_number);

    // success = 1
    // failure <= 0
    int status = inet_pton (AF_INET, ip_address, &(server_ipv4_addr.sin_addr.s_addr));
    if (status <= 0)
    {
        perror ("inet_pton");

	// clean up
	close (tcp_ipv4_listen_sock);
	return -1;
    }
    printf ("%s:: socket structure updated\n", __func__);

    // success = 0
    // failure = -1
    status = bind (tcp_ipv4_listen_sock, (struct sockaddr*) &server_ipv4_addr, sizeof (struct sockaddr_in));
    if (status < 0)
    {
        perror ("bind");

	// clean up
	close (tcp_ipv4_listen_sock);
	return -1;
    }
    printf ("%s:: socket bind success\n", __func__);
    printf ("%s:: returning socket fd:: %d\n", __func__, tcp_ipv4_listen_sock);

    return tcp_ipv4_listen_sock;
}

int main (int argc, char **argv)
{

    int listen_sock_fd = 0;
    listen_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock_fd < 0)
    {
        perror ("socket");
	exit (EXIT_FAILURE);
    }

    printf ("socket created: fd=%d\n", listen_sock_fd);

    int ret_status = 0;
    int sock_opt = 1;
    ret_status = setsockopt(listen_sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &sock_opt, sizeof(sock_opt));
    if (ret_status < 0)
    {
        perror ("setsockopt");

	// clean up
	close (listen_sock_fd);
	listen_sock_fd = 0;

	exit (EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_NUMBER);
    inet_pton (AF_INET, "192.168.165.183", &(server_address.sin_addr.s_addr));

    ret_status = bind (listen_sock_fd, (struct sockaddr*) &server_address, sizeof (server_address));
    if (ret_status < 0)
    {
        perror ("bind");

	// clean up
	close (listen_sock_fd);
	listen_sock_fd = 0;

	exit (EXIT_FAILURE);
    }

    printf ("bind successsful\n");

    ret_status = listen (listen_sock_fd, 5);
    if (ret_status < 0)
    {
        perror ("listen");

	// clean up
	close (listen_sock_fd);
	listen_sock_fd = 0;

	exit (EXIT_FAILURE);
    }

    char serv_addr[INET_ADDRSTRLEN] = {0};
    inet_ntop (AF_INET, &(server_address.sin_addr.s_addr), serv_addr, sizeof (struct sockaddr_in));
    printf ("listening on: %s:%d\n", serv_addr, PORT_NUMBER);

    int accept_sock_fd = 0;
    struct sockaddr_in client_address;
    int client_address_len = sizeof (struct sockaddr_in);

    accept_sock_fd = accept (listen_sock_fd, (struct sockaddr*) &client_address, &client_address_len);
    if (accept_sock_fd < 0)
    {
        perror ("accept");

	// clean up
	close (listen_sock_fd);
	listen_sock_fd = 0;

	exit (EXIT_FAILURE);
    }

    char client_addr[INET_ADDRSTRLEN] = {0};
    inet_ntop (AF_INET, &(client_address.sin_addr.s_addr), client_addr, sizeof (struct sockaddr_in));

    printf ("received connection from:\n");
    printf ("\tfd: %d\n", accept_sock_fd);
    printf ("\taddress: %s:%d\n", client_addr, ntohs (client_address.sin_port));

    send (accept_sock_fd, "hello from server", 18, 0);


    // clean up
    printf ("cleaning up...\n");
    close (listen_sock_fd);
    close (accept_sock_fd);
    listen_sock_fd = 0;
    accept_sock_fd = 0;

    return 0;
}
