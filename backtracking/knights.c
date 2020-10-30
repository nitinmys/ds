#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define occupy (boardmap, row, col) (boardmap |= 1ul <<((8*row) + col))
#define vacate (boardmap, row, col) (boardmap &= ~(1ul <<((8*row) + col)))
#define FULL_BOARD 0xffffffffffffffff
unsigned long boardmap = 0;
int board[8][8];

int main ()
{
	solve_knights(0,0);
}

solve_knights(row,col)
{
	int i,j;
	if (boardmap == FULL_BOARD)
	{
		print_board();
		return;
	}
	 
	






