#include<stdio.h>
#include <stdlib.h>
#include <strings.h>
int fib(int x);
int *arrptr;
int main(int argc, char *argv[])
{
    int n;
    n = atoi(argv[1]);
    arrptr = (int *)malloc (n * sizeof(int));
    bzero (arrptr, n* (sizeof(int)));
    printf ("fib(%d) = %d\n",n,fib(n));
}

int fib (int x)
{
    int y;
    if (x <= 1)
        return x;
    if (arrptr[x] == 0)
    {
        y = fib(x-1) + fib (x-2);
        arrptr[x] = y;
        return (y);
    }
    else
    {
        return (arrptr[x]);
    }
}
    


