//#define _CRT_SECURE_NO_WARNINGS
//
//#include "game.h"
//
//void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < rows; i++)
//	{
//		for (j = 0; j < cols; j++)
//		{
//			arr[i][j] = set;
//		}
//	}
//}
//
//void DisplayBoard(char arr[ROWS][COLS], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (j = 0; j <= col; j++)
//	{
//		printf("%d ", j);
//	}
//	printf("\n");
//	for (i = 1; i <= row; i++)
//	{
//		printf("%d ", i);
//		for (j = 1; j <= col; j++)
//		{
//			printf("%c ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void SetMine(char mine[ROWS][COLS], int row, int col)
//{
//	int count = EASY_COUNT;
//	while (count)
//	{
//		int x = rand() % row + 1;
//		int y = rand() % col + 1;
//		if (mine[x][y] == '0')
//		{
//			mine[x][y] = '1';
//			count--;
//		}
//	}
//}
//
//int GetMineCount(char mine[ROWS][COLS], int x, int y)
//{
//	return mine[x - 1][y] +
//		mine[x - 1][y - 1] +
//		mine[x][y - 1] +
//		mine[x + 1][y - 1] +
//		mine[x + 1][y] +
//		mine[x + 1][y + 1] +
//		mine[x][y + 1] +
//		mine[x - 1][y + 1]-8*'0';
//}
//
//void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	int win = 0;
//	while (win < row * col - EASY_COUNT)
//	{
//		printf("����������:>");
//		scanf("%d %d", &x, &y);
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (mine[x][y] == 1)
//			{
//				printf("���ź����㱻ը����\n");
//				DisplayBoard(mine, row, col);
//				break;
//			}
//			else
//			{
//				show[x][y] = GetMineCount(mine, x, y)+'0';
//				DisplayBoard(show, row, col);
//				win++;
//			}
//		}
//		else
//		{
//			printf("���������������������:>");
//		}
//	}
//	if (win = row*col - EASY_COUNT)
//	{
//		printf("��ϲ�㣬���׳ɹ���\n");
//		DisplayBoard(mine, row, col);
//	}
//}
//
//void game()
//{
//	char mine[ROWS][COLS];
//	char show[ROWS][COLS];
//	InitBoard(mine, ROWS, COLS,'0');
//	InitBoard(show, ROWS, COLS,'*');
//	//DisplayBoard(mine, ROW, COL);
//	//DisplayBoard(show, ROW, COL);
//	SetMine(mine, ROW, COL);
//	//DisplayBoard(mine, ROW, COL);
//	DisplayBoard(show, ROW, COL);
//	FindMine(mine, show, ROW, COL);
//
//
//
//
//
//
//}