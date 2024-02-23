#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#include <pthread.h>

int PORT_NUMBER  = 1025;
#define SERVER_PORT 8181

pthread_mutex_t mlock;

int number_of_connections = 0;

void* create_tcp_ipv4_client_socket (void* arg)
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

// comment out client bind: start
#if 0
    pthread_mutex_lock (&mlock);
    ++PORT_NUMBER;
    pthread_mutex_unlock (&mlock);
    struct sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons (PORT_NUMBER);
    inet_pton (AF_INET, "172.31.11.151", &(client_address.sin_addr.s_addr));

    ret_status = bind (client_sock_fd, (struct sockaddr*) &client_address, sizeof (struct sockaddr_in));
    if (ret_status)
    {
        perror ("bind");

	// clean up
	close (client_sock_fd);

	exit (EXIT_FAILURE);
    }
#endif
// comment out client bind: end

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons (SERVER_PORT);
    inet_pton (AF_INET, "127.0.0.1", &(server_address.sin_addr.s_addr));

    printf ("client tid:: %ld, trying to connect to server...\n", pthread_self());
    ret_status = connect (client_sock_fd, (struct sockaddr*) &server_address, sizeof (struct sockaddr_in));
    if (ret_status)
    {
        perror ("connect");

	// clean up
	close (client_sock_fd);

	exit (EXIT_FAILURE);
    }

    pthread_mutex_lock (&mlock);
    ++number_of_connections;
    printf ("total number of connections:: %d\n", number_of_connections);
    pthread_mutex_unlock (&mlock);

    char read_buff[1024] = {0};
    while (true)
    {
        int read_len = read (client_sock_fd, read_buff, sizeof (read_buff));
        if (read_len <=0 )
        {
            perror ("read");
	    close (client_sock_fd);
	    exit (EXIT_FAILURE);
        }
	sleep (2);
	char write_buff [1024] = "this is client sending message";
	send (client_sock_fd, write_buff, strlen(write_buff), 0);

        //printf ("client tid:: %ld - from server: \n%s\n", pthread_self(), read_buff);
        //close (client_sock_fd);
        //client_sock_fd = 0;
    }

    return NULL;
}

int main (int argc, char **argv)
{
    pthread_t tid [104857];
    pthread_mutex_init (&mlock, NULL);
    for (int i=0; i<104857; ++i)
    {
        pthread_create (&tid[i], NULL, create_tcp_ipv4_client_socket, NULL);
	//sleep (1);
    }

    for (int i=0; i<104857; ++i)
    {
        pthread_join(tid[i], NULL);
    }
    printf ("final total number of connections:: %d", number_of_connections);

    return 0;
}
