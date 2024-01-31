#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX 10

void *gstatus;

void* simple_count (void *arg)
{
    int *start = (int*)arg;
    gstatus = (int*) malloc (sizeof (int));
    *(int*) gstatus = 100;
    if (*start >= MAX)
    {
        pthread_exit (&gstatus);
    }

    for (int i=*start; i<MAX; ++i)
    {
        printf ("%d\n", i);
    }
    *(int*) gstatus = 200;
    pthread_exit (&gstatus);
}

int main ()
{
    pthread_t thread_tid;
    int start = 10;
    void *thread_status;
    pthread_create (&thread_tid, NULL, simple_count, (void*) &start);

    pthread_join (thread_tid, &thread_status);

    printf ("thread_status: %d\n", **(int**)thread_status);
    return 0;
}
