#include<stdio.h>
#include <stdlib.h>
int fib(int x);
int main(int argc, char *argv[])
{
    int n;
    n = atoi(argv[1]);
    printf ("fib(%d) = %d\n",n,fib(n));
}

int fib (int x)
{
    //printf ("calculating fib %d\n",x);
    if (x <= 1)
        return x;
    return (fib(x-1) + fib (x-2));
}
