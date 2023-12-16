#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int counter = 0;
pthread_mutex_t lock;

void *print_num(void *args)
{
    pthread_mutex_lock(&lock);
    counter += 1;
    printf("job %d has started...\n", counter);
    for(int i=0; i<100000; ++i)
	    ;

    printf("job %d has stopped...\n", counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}


int main()
{
    pthread_t tid[2];

    pthread_mutex_init(&lock, NULL);

    for (int i=0; i<2; ++i)
    {
         int error = pthread_create(&tid[i], NULL, &print_num, NULL);
         if (error == 0)
	 {
              printf("i=%d - thread created successfully\n", i);
	 }
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}
