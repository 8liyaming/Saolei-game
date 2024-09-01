#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
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
	printf("-----扫雷游戏-----\n");
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i); //打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----扫雷游戏-----\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//布置EASY_COUNT个雷
	int count = EASY_COUNT;
	while (count)
	{
		//产生随机的下标
		int x = rand() % ROW + 1;
		int y = rand() % ROW + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
} 

static int get_mine_count(char mine[ROWS][COLS], int x, int y) //加了stadic就只在该源文件中使用
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1. 输入排查的坐标
	//2. 检查坐标处是不是雷
		 //（1）是雷 - 很遗憾被炸死 - 游戏结束
		 //（2）不是雷 - 统计坐标周围有几个雷 - 存储到show数组，游戏结束
	int x = 0;
	int y = 0;
	int win = 0;

	while (win < row * col - EASY_COUNT)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d%d", &x, &y);

		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//不是雷的情况下，统计坐标（x，y）周围有几个雷
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0'; //因为得到的count是数字，这里要输出到show数组里面的是字符
				//显示排查出的信息
				DisplayBoard(show, row, col);
				win ++;
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, row, col);
	}
}