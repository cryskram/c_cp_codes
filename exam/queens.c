#include <stdio.h>
#define N 10

int board[N][N];

int isSafe(int r, int c)
{
    for (int i = 0; i < r; i++)
        if (board[i][c] || (c - i + r < N && board[i][c - i + r]) || (c + i - r >= 0 && board[i][c + i - r]))
            return 0;
    return 1;
}

int solve(int r)
{
    if (r == N)
        return 1;
    for (int c = 0; c < N; c++)
    {
        if (isSafe(r, c))
        {
            board[r][c] = 1;
            if (solve(r + 1))
                return 1;
            board[r][c] = 0;
        }
    }
    return 0;
}

void printBoard()
{
    for (int i = 0; i < N; i++, printf("\n"))
        for (int j = 0; j < N; j++)
            printf("%c ", board[i][j] ? 'Q' : '.');
}

int main()
{
    if (solve(0))
        printBoard();
    else
        printf("No solution\n");
    return 0;
}