#include <stdio.h>

#define PORT_NUMBER 9090
#define SERVER_PORT 8181

int main (int argc, char **argv)
{
    int client_sock_fd = socket (AF_INET, SOCK_STREAM, 0);
    if (client_sock_fd < 0)
    {
        perror ("socket");
	exit (EXIT_FAILURE);
    }

    int sock_opt = 1;
    int ret_status = setsockopt (client_sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &sock_opt, sizeof (sock_opt));
    if (ret_status)
    {
        perror ("setsockopt");

	// clean up
	close (client_sock_fd);

	exit (EXIT_FAILURE);
    }

    struct sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons (PORT_NUMBER);
    inet_ptons ();

    ret_status = bind (client_sock_fd, (struct sockaddr*) &client_address, sizeof (struct sockaddr_in));
    if (ret_status)
    {
        perror ("bind");

	// clean up
	close (client_sock_fd);

	exit (EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons (SERVER_PORT);
    inet_ptons ();

    ret_status = connect (client_sock_fd, (struct sockaddr*) &server_address, sizeof (struct sockaddr_in));
    if (ret_status)
    {
        perror ("connect");

	// clean up
	close (client_sock_fd);

	exit (EXIT_FAILURE);
    }
}
