#include <stdio.h>

#define MAX 20

int num = 1;

pthread_mutex_t mlock;

void* print_odd (void *arg)
{
    if (num > MAX)
    {
        pthread_exit(NULL);
    }
    while (num <= MAX)
    {
        if (num%2 != 0)
	{
            pthread_mutex_lock(&mlock);
            printf ("%d ", num);
	    ++num;
            pthread_mutex_unlock(&mlock);

	}
    }
}

void* print_even (void *arg)
{
    if (num > MAX)
    {
        pthread_exit(NULL);
    }
    while (num <= MAX)
    {
        if (num%2 == 0)
	{
            printf ("%d ", num);
	    ++num;
	}
    }
}

int main ()
{
    pthread_t tid[2];
    pthread_mutex_init(&mlock, NULL);

    pthread_create (&tid[0], NULL, print_odd, NULL);   
    pthread_create (&tid[1], NULL, print_even, NULL);   

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    return 0;
}


