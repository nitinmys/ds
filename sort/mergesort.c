#include <stdio.h>
#include <string.h>
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


int *  merge (int a[], int b[], int sizel,int sizer)
{
    int i=0,j=0,k=0,l=0;
    int c[10];
    int size = sizel + sizer;
    printf ("merge: a[0]=%d b[0]= %d lzise= %d rsize = %d\n",a[0],b[0],sizel,sizer);
    for (i = 0 ; i < size ; i++)
    {
        if (a[j] < b[k])
        {
            c[i] = a[j++];
            if (j == sizel)
            {
                //printf ("copying right array j = %d sizel = %d\n",j,sizel);
            
                for (l =k ; l < sizer ; l++)
                    c[++i] = b[l];
                break;
            }
        }
        else
        {
            c[i] = b[k++];
            if (k == sizer)
            {
                //printf ("copying right array k = %d sizer = %d\n",k,sizer);
                for (l = j ; l < sizer ; l++)
                     c[++i] = b[l];
                break;

            }
        }
        //printf ("size = %d i=%d j=%d k=%d c[i]= %d\n",size,i,j,k,c[i]);
    }
    return a;
}


int * merge_sort (int a[],int size)
{
    //printf ("size passed=%d\n",size);
    //prtarray();
    if (size == 1)
    {
        return (a);
    }
    else if (size == 2)
    {
        if (a[0] > a[1])
        {
            printf ("before swap: a[0]=%d a[1]= %d\n",a[0],a[1]);
            swap (&a[0],&a[1]);
            printf ("after swap: a[0]=%d a[1]= %d\n",a[0],a[1]);
            return (a);
        }
        else
            return (a);
    }
    else
    {
        return (merge (merge_sort(a,size/2), merge_sort (&a[size/2],size - size/2), size, (size-size/2)));
    }
}

int main()
{
    int i;
    prtarray();
    merge_sort (arr,10);

    for (i = 0; i < 10 ; i++)
          printf ("%d\t",arr[i]);
     printf ("\n");
}




