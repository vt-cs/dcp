#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

#define PORT_NUMBER 8181
#define MAX_BACKLOG 5


int main(int argc, char **argv)
{
    int listen_sock_fd;
    int accept_sock_fd;

    int socket_opt = 1;
    int return_status;

    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    int client_address_len = sizeof(client_address);

    char read_buffer[1024] = {0};
    char *server_hello = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\nConnection: close\r\n\r\nHello, world!";

    listen_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_sock_fd < 0)
    {
        perror("socket error");
	exit(EXIT_FAILURE);
    }

    return_status = setsockopt(listen_sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &socket_opt, sizeof(socket_opt));
    if(return_status < 0)
    {
        perror("setsockopt error");
	exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUMBER);

    return_status = bind(listen_sock_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    if(return_status < 0)
    {
        perror("bind error");
	exit(EXIT_FAILURE);
    }

    return_status = listen(listen_sock_fd, MAX_BACKLOG);
    if(return_status < 0)
    {
        perror("listen error");
	exit(EXIT_FAILURE);
    }

    accept_sock_fd = accept(listen_sock_fd, (struct sockaddr*)&client_address, &client_address_len);
    if(accept_sock_fd < 0)
    {
        perror("accept error");
	exit(EXIT_FAILURE);
    }

    read(accept_sock_fd, read_buffer, sizeof(read_buffer)-1);
    printf("read from client:\n\n%s\n", read_buffer);

    printf("server sending response\n");
    send(accept_sock_fd, server_hello, strlen(read_buffer), 0);

    close(accept_sock_fd);
    close(listen_sock_fd);

    return 0;
}
