#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
 
struct thread_data{
#define T_SLEEPING          0x1
#define T_DESTROY        0x2
#define T_WORK5           0x4
#define T_WORK10        0x8

#define T_WORK T_WORK5 | T_WORK10 | T_DESTROY
    int flags;
};

struct thread_data t;

struct thread_data *thread = &t;
    

pthread_cond_t cond  = 
               PTHREAD_COND_INITIALIZER;

pthread_cond_t cond2  = 
               PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
   

void *thread_func(void *n)
{
    int flags;
    pthread_mutex_lock (&lock);
     pthread_cond_signal (&cond2);
    do
    {
        if (!thread->flags & T_WORK)
        {
            thread->flags |= T_SLEEPING;
            printf ("going to sleep for work\n");
            pthread_cond_wait (&cond,&lock);
        }
        // woken up by work
       
        thread->flags &= ~T_SLEEPING;
        flags = thread->flags;
        thread->flags &= ~( T_WORK5 | T_WORK10);
         printf ("got work = %d\n",flags);
        // release lock
        pthread_mutex_unlock(&lock);
        if (flags & T_WORK5)
        {
            printf ("sleeping for 5 seconds\n");
            sleep(1);
        }
        if (flags & T_WORK10)
        {
            printf ("sleeping for 10 seconds\n");
            sleep(1);
        }
        pthread_mutex_lock (&lock);
    } while (! (flags & T_DESTROY));

    pthread_mutex_unlock(&lock);
    printf ("thread destroyed");
}

void send_signal(int work)
{
        pthread_mutex_lock (&lock);
        thread->flags |= work;
        if (thread->flags & T_SLEEPING)
        {
             printf ("thread sleeping.. waking it up\n");
            pthread_cond_signal (&cond);
        }
        pthread_mutex_unlock (&lock);
}

  
// Driver code
int main()
{
        pthread_t  tid1;
        int n1,i;
          pthread_mutex_lock (&lock);
        
        pthread_create(&tid1, NULL, thread_func, (void *)&n1);
        //thread->flags |= T_WORK5;

        
        //pthread_mutex_unlock (&lock);

    
        pthread_cond_wait (&cond2,&lock);
        printf ("threads created\n");
        pthread_mutex_unlock (&lock);

        sleep(1);
        

        send_signal(T_WORK5);


         sleep(1);
        
         send_signal(T_WORK10);


       sleep (5);

     send_signal(T_DESTROY);

    for (i = 0 ; i < 100; i++)
    {
        send_signal(T_WORK5);
    }
    pthread_join (tid1,NULL);
    return 0;
}
