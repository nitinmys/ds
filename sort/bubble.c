#include <stdio.h>
int arr[10]={8,3,6,1,2,9,0,5,11,4};
void prtarray()
{
    int i;
    for (i = 0; i < 10 ; i++)
         printf ("%d\t",arr[i]);
    printf ("\n");
}
void swap (int *a,int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
int main()
{
    int i,j,n=10;
    for (i = 0; i < n-2 ; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
                swap (&arr[j],&arr[j+1]);
        }
        prtarray();
    }
    prtarray();
    printf ("\n");
}


