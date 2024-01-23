#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>

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

    printf ("socket created. fd:%d\n", client_sock_fd);

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
    inet_pton (AF_INET, "192.168.165.183", &(client_address.sin_addr.s_addr));

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
    inet_pton (AF_INET, "192.168.165.183", &(server_address.sin_addr.s_addr));

    ret_status = connect (client_sock_fd, (struct sockaddr*) &server_address, sizeof (struct sockaddr_in));
    if (ret_status)
    {
        perror ("connect");

	// clean up
	close (client_sock_fd);

	exit (EXIT_FAILURE);
    }

    char read_buff[1024] = {0};
    int read_len = read (client_sock_fd, read_buff, sizeof (read_buff));
    if (read_len <=0 )
    {
        perror ("read");

	close (client_sock_fd);
	
	exit (EXIT_FAILURE);
    }

    printf ("from server: \n%s\n", read_buff);

    close (client_sock_fd);
    return 0;
}
