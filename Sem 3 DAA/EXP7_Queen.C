#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int board[8]; // Assuming 8x8 chessboard

int place(int row, int column)
{
    // Check if placing the queen at given row and column results in any conflicts
    int i;
    for (i = 0; i < row; i++)
    {
	if (board[i] == column || abs(board[i] - column) == abs(i - row))
	{
	    return 0;
	}
    }
    return 1;
}

void print_board(int n)
{
    // Print the current configuration of the board
    int i;
    int j;
    for (i = 0; i < n; i++)
    {
	for (j = 0; j < n; j++)
	{
	    if (board[i] == j)
	    {
		printf("Q ");
	    }
	    else
	    {
		printf(". ");
	    }
	}
	printf("\n");
    }
    printf("\n");
    printf("Press any key to continue...\n");
    getch(); // Wait for a key press before continuing
}

void Queen(int row, int n)
{
    // Recursive function to place queens
    int column;

    for (column = 0; column < n; column++)
    {
	if (place(row, column))
	{
	    board[row] = column;
	    if (row == n - 1)
	    {
		print_board(n);
	    }
	    else
	    {
		Queen(row + 1, n);
	    }
	}
    }
}

int main()
{
    Queen(0, 8);
    return 0;
}
