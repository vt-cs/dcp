#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mlock;

int resource = 0;

void* thread_fun_1 (void *arg)
{
    pthread_mutex_lock(&mlock);
    ++resource;
    printf ("resource = %d\n", resource);
    pthread_mutex_unlock(&mlock);

    return NULL;
}

void* thread_fun_2 (void *arg)
{
    pthread_mutex_lock(&mlock);
    ++resource;
    printf ("resource = %d\n", resource);
    pthread_mutex_unlock(&mlock);

    return NULL;
}

int main (int argc, char **argv)
{
    pthread_t thread_id[2];

    pthread_mutex_init (&mlock, NULL);

    pthread_create (&thread_id[0], NULL, thread_fun_1, NULL);
    pthread_create (&thread_id[1], NULL, thread_fun_2, NULL);

    pthread_join (thread_id[0], NULL);
    pthread_join (thread_id[1], NULL);

    return 0;
}
