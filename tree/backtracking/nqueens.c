#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printvalues (int **arr, int r, int c);
int checkvalid(int row, int col, int **arr,int size);
void nqueens(int **arr,int row,int size);
int num_solution = 0;
 
int main(int argc , char *argv[])
{
    
    int i,j,row,col;
	 int **a; 
	row = atoi(argv[1]);
	col = row;
   	a = (int **) malloc (sizeof(int *) * row);
    for (i = 0; i < row; i++)
        a[i] = (int *) malloc (sizeof(int) * col);

    for (i = 0 ; i < row ; i++)
        for (j =0; j < col; j ++)
        a[i][j] = 0;

    //printvalues (a, row,col);
	nqueens (a, 0, row);
	printf ("Total number of solutions = %d\n",num_solution); 
    return 0;
}
int checkvalid(int row, int col, int **arr, int size)
{
	int i,	j;
	for (i = row; i >= 0; i--)
	{
		if (arr[i][col] == 1)
			return 0;
	}

	i = row; j = col;

	while (i > 0 && j > 0)
	{
			if (arr[--i][--j] == 1)
				return 0;
		} 

	i = row; j = col;

	while (i > 0 && j < (size-1))
    {
			if (arr[--i][++j] == 1)
				return 0;
	} 

	return 1;
}


void nqueens(int **arr,int row,int size)
{
	int i;
	if (row == size)
	{
		// we have reached end of board print solution
		//printvalues(arr, size, size);
		num_solution++;
		return;
	}

	for (i = 0; i < size; i++)
	{
		if (checkvalid(row, i , arr, size))
		{
			arr[row][i] = 1;
			//printvalues(arr, size, size);
			nqueens (arr, row+1, size);
			arr[row][i] = 0;
		}
	}
}


void printvalues (int **arr, int r, int c)
{
    int i,j;
    	for (i = 0 ; i < r ; i++)
		{
        	for (j =0; j < c; j ++)
        		printf ("%d\t",arr[i][j]);
			printf ("\n");
		}
	printf ("\n");
}
