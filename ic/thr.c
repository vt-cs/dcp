#include <stdio.h>


int res = 0;

pthread_mutex_t mlock;

void* t1 (void *args)
{
    // something
    pthread_mutex_lock(&mlock);
    // use res;
    pthread_mutex_unlock(&mlock);
}

void* t2 (void *args)
{
}


int main ()
{

    pthread_mutex_init (&mlock, NULL);
    pthread_create(&tid1, NULL, t1, (void*) &res);
    pthread_create(&tid2, NULL, t2, (void*) &res);
}
