#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int  get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	int z= mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x - 1][y] + mine[x + 1][y]
		+ mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] - 8 * '0';
	return z;
}
void F(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	show[x][y] = ' ';
	show[x - 1][y - 1] = ' ';
	show[x][y - 1] = ' ';
	show[x + 1][y - 1] = ' ';
	show[x - 1][y] = ' ';
	show[x + 1][y] = ' ';
	show[x - 1][y + 1] = ' ';
	show[x][y + 1] = ' ';
	show[x + 1][y + 1] = ' ';
}
void f(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int a = get_mine_count(mine, x-1, y - 1);
	if ( a == 0)
	{
		F(mine,show, x - 1, y - 1);
	}
	int b= get_mine_count(mine, x , y - 1);
	if (b == 0)
	{
		F(mine, show, x , y - 1);
	}
	int c= get_mine_count(mine, x+1, y - 1);
	if (c == 0)
	{
		F(mine, show, x+1, y - 1);
	}
	int d= get_mine_count(mine, x -1, y );
	if (d == 0)
	{
		F(mine, show, x - 1, y );
	}
	int e = get_mine_count(mine, x + 1, y );
	if (e == 0)
	{
		F(mine, show, x + 1, y );
	}
	int f = get_mine_count(mine, x - 1, y + 1);
	if (f == 0)
	{
		F(mine, show, x - 1, y + 1);
	}
	int g = get_mine_count(mine, x , y + 1);
	if (g == 0)
	{
		F(mine, show, x , y + 1);
	}
	int h = get_mine_count(mine, x+1, y + 1);
	if (h == 0)
	{
		F(mine, show, x+1, y + 1);
	}

}
void FindMine(char mine[ROWS][COLS], char show [ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if (x <= row && x >= 1 && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("It's a pity that you're blown up!\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y);
				if (count != 0)
				{
					show[x][y] = count + '0';
					DisplayBoard(show, ROW, COL);
					win++;
				}
				else
				{
					F(mine,show, x, y);
					f(mine,show, x, y);
					DisplayBoard(show, ROW, COL);
				}
			}
		}
		else
		{
			printf("坐标非法，请重新输入！");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("Congratulations!\n");
	}
}
