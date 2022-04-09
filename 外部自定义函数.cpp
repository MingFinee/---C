#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int visual = 2022;

int add(int x, int y)
{
	int z;
	z = x + y;
	return z;
}

//三子棋
//int menu()
//{
//	printf("**********************\n");
//	printf("****1.play  2.exit****\n");
//	printf("**********************\n");
//	return 0;
//}
//
//#include "game.h"//头文件里定义了row，col
//void init_g(char g[row][col], int r, int c)
//{
//	int i;
//	int j;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			g[i][j] = ' ';
//		}
//	}
//}
//
//void p_g(char g[row][col],int r,int c)	
//{
//	int i;
//	int j;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			printf(" %c ", g[i][j]);
//			if (j < c - 1)
//				printf("|");
//		}
//		printf("\n");
//		if (i < r-1)
//		{
//			for (j = 0; j < c; j++)
//			{
//				printf("---");
//				if (j < c - 1)
//					printf("|");
//			}
//			printf("\n");
//		}
//	}
//}
//
//void Player_Move(char g[row][col], int r, int c)
//{
//	int x, y;
//	while (1)     //永远循环，除非break
//	{
//		printf("请输入坐标：\n");    
//		scanf("%d%d", &x, &y);    //输入时记得打空格，否则会认为是一个数字
//		if (x >= 1 && x <= r && y >= 1 && y <= c)  //判断x，y的合理性（带入玩家想法）
//		{
//			if (g[x - 1][y - 1] == ' ')
//			{
//				g[x - 1][y - 1] = '*';
//				break;
//			}
//			else
//			{
//				printf("该坐标被占用，请重新输入：\n");
//			}
//		}
//		else
//			printf("坐标错误，请重新输入：\n");
//	}
//}
//
//void Computer_Move(char g[row][col], int r, int c)
//{
//	int x;
//	int y;
//	printf("电脑走\n");
//	srand((unsigned int)time(NULL));
//	while (1)
//	{
//		x = rand() % r;  //取余之后小于r
//		y = rand() % c;
//		if (g[x][y] == ' ')
//		{
//			g[x][y] = '#';
//			break;
//		}
//	}
//}
//
//int full(char g[row][col], int r, int c)
//{
//	int x, y;
//    for (x = 0; x < r;x++)
//    {
//		for (y = 0; y < c; y++)
//		{
//			if (g[x][y] == ' ')
//			{
//				return 0;
//			}
//		}
//     } 
//	return 1;
//}
//char winer(char g[row][col], int r, int c)//暴力法[doge]
//{
//	int i;
//	for (i= 0; i< r; i++)        //三行
//	{
//		if (g[i][0] == g[i][1]&& g[i][1] == g[i][2] &&  g[i][2] != ' ')
//		{
//			if (g[i][0] == '*')
//				return '1';
//			else return '2';
//		}
//	}
//	for (i = 0; i < r; i++)        //三列
//	{
//		if (g[0][i] == g[1][i] && g[1][i]== g[2][i] && g[2][i]!=' ')
//		{
//			if (g[i][0] == '*')
//				return '1';
//			else return '2';
//		}
//	}
//	if(g[0][0]==g[1][1]&& g[1][1]==g[2][2] &&g[2][2] !=' ')  //两个对角线
//	{
//		if (g[i][0] == '*')
//			return '1';
//		else 
//			return '2';
//	}
//	if (g[2][0] == g[1][1] && g[1][1] == g[0][2] && g[2][0] != ' ')
//	{
//		if (g[i][0] == '*')
//				return '1';
//		else 
//			return '2';
//	}
//	if (full(g, r, c) == 1)  //判断继续
//	{
//		return '4';
//	}
//	return '3';
//}



//扫雷
int menu()
{
	printf("**********************\n");
	printf("****1.play  2.exit****\n");
	printf("**********************\n");
	return 0;
}
#include "game.h"
void init_g(char g[ROW][COL], int r, int c)
{
	int i;
	int j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			g[i][j] = '0';
		}
	}
}
void init_g(char g[a][b], int r, int c)
{
	int i;
	int j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			g[i][j] = '*';
		}
	}
}

void p_g(char g[a][b], int r, int c)
{
	int i;
	int j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf(" %c ", g[i][j]);
			if (j < c - 1)
				printf("|");
		}
		printf("\n");
		if (i < r-1)
		{
			for (j = 0; j < c; j++)
			{
				printf("---");
				if (j < c - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void p_g(char g[ROW][COL], int r, int c)
{
	int i;
	int j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%c",g[i][j]);
		}
		printf("\n");
	}
}

 void SetMine(char g[ROW][COL], int r, int  c)
 {
	 srand(unsigned int(time(NULL)));
	 int m = count;
	 while (m)   //已在game.h中定义
	 {
		 int x = rand() % r+1;
		 int y = rand() % c+1;  //1~9,第2到第10格
		 if (g[x][y] == '0')
		 {
			 g[x][y] = '1';
			 m--;
		 }
	 }
 }

 int compare(char hidden[ROW][COL],int x,int y)
 {
	 return (hidden[x-1][y]+ hidden[x][y-1]+hidden[x+1][y-1]+ hidden[x-1][y-1]
		 + hidden[x+1][y]+ hidden[x][y+1]+ hidden[x-1][y+1]+ hidden[x+1][y+1]
		 -8*'0');   //  '1'-'0'=1 ; '3'-'0'=3;查ASCII码可知
 }
 void FindMine(char showing[a][b], char hidden[ROW][COL], int r, int c)
 {
	 int x, y;
	 int i=0;
	 char n=0;
	 while (i<81-n)
	 {
		 printf("请输入坐标：\n");
		 scanf("%d%d", &x, &y);
		 if (x >= 1 && x <= r && y >= 1 && y <= c)
		 {
			 if (showing[x-1][y-1] == '*')
			 {
				 if (hidden[x][y] == '1')
				 {
					 printf("你踩雷了\n");
					 p_g(hidden, ROW, COL);
					 break;
				 }
				 else
				 {
					 int n = compare(hidden,x,y);
					 showing[x-1][y-1] = n+'0';
					 i++;
					 p_g(showing, a, b);
				 }
			 }
			 else
			 {
				 printf("坐标重复，请重新输入：\n");
			 }
		 }
		 else
			 printf("非法输入，请重新输入：\n");
	 }
if(i >=81 - n)
	printf("恭喜你，排完了\n");
 }
