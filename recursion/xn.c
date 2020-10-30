#include<stdio.h>
#include <stdlib.h>
int xn(int x,int ni, int result);
int main(int argc, char *argv[])
{
    int x,n,k;
    float res;
    x = atoi(argv[1]);
    n = atoi(argv[2]);
    if (n < 0)
    {
        k = n * -1;
    }
    else
    {

        k = n;

    }
    res = xn(x,k,1);
    if (n < 0)
    {
        res = 1 / res;
        printf ("xn(%d,%d) = %f\n",x,n,res);
    }
    else
        printf ("xn(%d,-%d) = %f\n",x,n,res);
}

int xn (int x, int n, int result)
{
    if (n == 0)
        return result;
    return (xn(x,n-1,result*x));
}
