#include <stdio.h>
int arr[10]={8,3,6,1,2,9,0,5,11,4};
findmin (int a[],int size)
{
    int lowest = a[0];
    int low = 0;
    int i;
    for (i = 0 ; i < size; i++)
    {
        if (a[i] < lowest){
            lowest = a[i];
            low = i;
        }
    }
    a[low] = a[0];
    return lowest;
}
int main()
{
    int i,n=10;
    for (i = 0; i < n ; i++)
         printf ("%d\t",arr[i]);
    printf ("\n");
    for (i = 0; i < n ; i++)
    {
        arr[i] = findmin (&arr[i],n - i);
    }
    for (i = 0; i < n ; i++)
        printf ("%d\t",arr[i]);
    printf ("\n");
}


