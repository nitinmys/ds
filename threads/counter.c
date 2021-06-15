#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_THREADS 3
#define TOTAL_COUNT 100
pthread_mutex_t lock;
pthread_t thr[3];
pthread_cond_t cond[4] = {PTHREAD_COND_INITIALIZER};
int global;
void * func (void *arg)
{
       int i, thr_to_wake;
        int *start = (int *) arg;
        
         pthread_mutex_lock(&lock);
     //    printf ("Thread %d got outer lock\n",*start);
     
         global++;

        for (i = *start; i<=TOTAL_COUNT; i+=NUM_THREADS)
        {

            //printf (" Thread %d executing pthread_cond_wait\n",*start);
            pthread_cond_wait (&cond[*start], &lock);
            if (i == TOTAL_COUNT)
                printf ("%d",i);
            else
                printf ("%d,",i);
            thr_to_wake = (*start +1) % NUM_THREADS;
            //printf (" Thread %d waking thread %d pthread_cond_signal\n",*start, thr_to_wake);
            pthread_cond_signal(&cond[thr_to_wake]);
        }
        pthread_mutex_unlock(&lock);
       
}
int main ()
{
    int i, data[3];
    pthread_t thr[3];
    pthread_mutex_init(&lock,NULL);
    global = 0;
    
    for (i = 0 ; i < 3; i++)
    {

        data[i] = i;
        pthread_create (&thr[i], NULL, func, &data[i]);
        
 
    }

    // poll till all threads get created.
    while (global <3);

    // ensure that all threads are waiting on condition
    pthread_mutex_lock(&lock);

    pthread_cond_signal(&cond[0]); 
    pthread_mutex_unlock(&lock);
   for (i = 0 ; i < 3; i++)
        pthread_join (thr[i],NULL);
}
