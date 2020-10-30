#include <stdio.h>
int arr[] = {1,2,3,5,4,6,7};
int num = 0;
int solution[8]= {0};

void prtsubsets (int index, int result, int current, int num_elems);
int main ()
{
    int n;
    n = sizeof(arr)/sizeof(int);
    prtsubsets(0, 8, 0, n);
    printf ("Number of subsets = %d\n",num);
    return 0;
}

void prtsubsets (int index, int result, int current, int num_elems)
{
    if (current > result)
    return;
    if (current == result)
    {
        int i;
        num++;
        for (i = 0 ; i < num_elems; i++)
        {
            if (solution[i] != 0)
                printf ("%d\t",arr[i]);
        }
       printf ("\n");
        return;
    }
    if (index == num_elems)
        return;

    solution[index] = 1;
    prtsubsets (index+1, result, arr[index] + current, num_elems);
    solution[index] = 0;
    prtsubsets (index+1, result, current, num_elems);
}
