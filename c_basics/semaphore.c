#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 10

sem_t sem_lock;
int i=1;

void* count_even (void *arg)
{
    int *start = (int*) arg;

    if (*start >= MAX)
    {
        pthread_exit (NULL);
    }

    while (i<MAX)
    {
	if (i%2 == 0)
	{
            printf ("%d\n", i);
	    sem_wait (&sem_lock);
	    ++i;
	    sem_post (&sem_lock);
	}
    }
}

void* count_odd (void *arg)
{
    int *start = (int*) arg;

    if (*start >= MAX)
    {
        pthread_exit (NULL);
    }

    while (i<MAX)
    {
	if (i%2 != 0)
	{
            printf ("%d\n", i);
	    sem_wait (&sem_lock);
	    ++i;
	    sem_post (&sem_lock);
	}
    }
}


int main (int argc, char **argv)
{
    pthread_t thread_ids[2];

    int e=2;
    int o=1;

    sem_init (&sem_lock, 0, 1);

    pthread_create (&thread_ids[0], NULL, count_odd, (void*)&o);
    pthread_create (&thread_ids[1], NULL, count_even, (void*)&e);

    pthread_join (thread_ids[0], NULL);
    pthread_join (thread_ids[1], NULL);

    sem_destroy (&sem_lock);

    return 0;
}
