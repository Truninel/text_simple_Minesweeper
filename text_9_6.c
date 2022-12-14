#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"

void menu()
{
	printf("************************************\n");
	printf("***********  1.play   **************\n");
	printf("***********  0.exit   **************\n");
	printf("************************************\n");
}
void game()
{
	char mine[ROWS][COLS]={ 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	SetMine(mine, ROW, COL);
	FindMine(mine,show, ROW, COL);

}
void text()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新选择\n");
		}
	} while (input);
}

int main()
{
	text();
	return 0;
}