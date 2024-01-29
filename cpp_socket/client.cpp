#include <iostream>

#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>


#define SERVER_PORT 8181
#define SERVER_IP_STR "127.0.0.1"

#define CLIENTPORT 9191
#define CLIENT_IP_STR "127.0.0.1"


int main (int argc, char **argv)
{
    int client_sock_fd = socket (AF_INET, SOCK_STREAM, 0);
    if (client_sock_fd < 0)
    {
        perror ("socket");
	return -1;
    }


    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons (SERVER_PORT);

    int status = inet_pton (AF_INET, SERVER_IP_STR, &(server_address.sin_addr.s_addr));
    if (status <= 0)
    {
        perror ("inet_pton");
	return -1;
    }

    struct sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons (CLIENTPORT);
    
    status = inet_pton (AF_INET, CLIENT_IP_STR, &(client_address.sin_addr.s_addr));
    if (status <= 0)
    {
        perror ("inet_pton");
	return -1;
    }

    status = bind (client_sock_fd, (struct sockaddr*) &client_address, sizeof (struct sockaddr_in));
    if (status < 0)
    {
        perror ("bind");
	return -1;
    }

    socklen_t client_addr_len = sizeof (struct sockaddr_in);
    status = connect (client_sock_fd, (struct sockaddr*) &server_address, client_addr_len);
    if (status < 0)
    {
        perror ("connect");
	return -1;
    }

    // clean up
    close (client_sock_fd);

    return 0;
}
