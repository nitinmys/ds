#include <stdio.h>
#include <stdlib.h>
int A[] = {10,2,3,4,5,7,8};

void print_result (int index_arr[], int n)
{
    int i;
    for (i = 0; i < n ; i++ )
    {
        if (index_arr[i])
            printf ("%d,",A[i]);
    }
    printf ("\n");
}


int add (int index_arr[], int n)
{
    int result = 0;
    int i;
    for (i = 0; i < n ; i++ )
    {
        if (index_arr[i])
            result += A[i];
    }
return result;
}

void get_sum(int index_arr[], int num_elems, int sum, int index)
{
    if (index == num_elems)
        return;
    if (add(index_arr, num_elems) == sum)
    {
        print_result (index_arr, num_elems);
        return;
    } 
    else
    {
        index_arr[index] = 0;
        get_sum (index_arr, 7, 23, index+1);
         index_arr[index] = 1;
        get_sum (index_arr, 7, 23, index+1);
    }
}
int main()
{
 int   N = 7, K = 23;
int index_arr[7] = {0};

get_sum (index_arr, 7, 23, 0);

return 0;
}
