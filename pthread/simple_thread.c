#include <stdio.h>
#include <pthread.h>

void* simple_thread(void *arg)
{
    int *iptr = (int*) arg;
    ++(*iptr);
    printf ("simple thread, arg=%d\n", *iptr);

    pthread_exit(NULL);
}

int main (int argc, char **argv)
{
    int val = 10;
    pthread_t thread_id;
    printf ("val=%d\nbefore calling thread\n", val);
    pthread_create (&thread_id, NULL, &simple_thread, &val);

    pthread_join (thread_id, NULL);
    printf ("val=%d\nafter thread exit\n", val);

    return 0;
}
