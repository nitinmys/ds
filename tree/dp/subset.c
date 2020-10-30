#include<stdio.h>
int arr[]= {1,4,3,2,6};
int subset (int n,int sum);
int main ()
{
    int n,sum,i;
    n = sizeof(arr)/sizeof(int);
    printf ("The Array is:\n");
    for (i = 0; i < n ; i++)
        printf ("%d \t",arr[i]);
    printf ("\n");
    scanf ("%d",&sum);
    printf ("calling subset (%d,%d)\n",n,sum);
    printf ("subset returned %d\n",subset(n,sum));
}

int subset (int n,int sum)
{
    printf ("called subset with n = %d sum = %d\n",n,sum);
    if (n == 0)
    {
        if (arr[0] == sum)
            return 1;
        else
            return 0;
    }
    else
    {
        if (arr[n-1] == sum)
            return 1;
        else
        {
            if (arr[n-1] > sum)
                return (subset (n-1,sum));
            else
                return (subset (n-1,sum-arr[n-1]) || subset (n-1,sum));

        }
    }
}
