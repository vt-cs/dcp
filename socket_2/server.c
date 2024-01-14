#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>


#define PORT_NUMBER 8181

int main (int argc, char **argv)
{

    int listen_sock_fd = 0;
    listen_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock_fd < 0)
    {
        perror ("socket");
	exit (EXIT_FAILURE);
    }

    int ret_status = 0;
    int sock_opt = 1;
    ret_status = setsockopt(listen_sock_fd, SOL_SOCKET, SO_REUSE_ADDR | SO_REUSE_PORT, &sock_opt, sizeof(sock_opt));
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
    server_address.sin_addr.s_addr = inet_pton();

    ret_status = bind (listen_sock_fd, (struct sockaddr*) &server_address, sizeof (server_address));
    if (ret_status < 0)
    {
        perror ("bind");

	// clean up
	close (listen_sock_fd);
	listen_sock_fd = 0;

	exit (EXIT_FAILURE);
    }

    ret_status = listen (listen_sock_fd, 5);
    if (ret_status < 0)
    {
        perror ("listen");

	// clean up
	close (listen_sock_fd);
	listen_sock_fd = 0;

	exit (EXIT_FAILURE);
    }

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


    // clean up
    close (listen_sock_fd);
    close (accept_sock_fd);
    listen_sock_fd = 0;
    accept_sock_fd = 0;

    return 0;
}
