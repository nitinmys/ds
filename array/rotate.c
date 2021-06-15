#include<stdio.h>
#include<stdlib.h>
void rotateone(int *a,int size)
{
    int i,temp;
    temp = a[0];
    for (i = 0; i < size; i++)
        a[i] = a[i+1];
    a[size-1] = temp;
}

int main ()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int rot = 5;
    int i;
    for (i = 0; i < rot; i++)
        rotateone(array,10);

for (i = 0; i <10; i++)
    printf ("%d\t",array[i]);
printf ("\n");
}
