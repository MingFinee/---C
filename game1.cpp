#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//������
int menu()
{
	printf("**********************\n");
	printf("****1.play  2.exit****\n");
	printf("**********************\n");
	return 0;
}

#include "game1.h"//ͷ�ļ��ﶨ����row��col
void init_g(char g[row][col], int r, int c)
{
	int i;
	int j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			g[i][j] = ' ';
		}
	}
}

void p_g(char g[row][col],int r,int c)	
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

void Player_Move(char g[row][col], int r, int c)
{
	int x, y;
	while (1)     //��Զѭ��������break
	{
		printf("���������꣺\n");    
		scanf("%d%d", &x, &y);    //����ʱ�ǵô�ո񣬷������Ϊ��һ������
		if (x >= 1 && x <= r && y >= 1 && y <= c)  //�ж�x��y�ĺ����ԣ���������뷨��
		{
			if (g[x - 1][y - 1] == ' ')
			{
				g[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ�ã����������룺\n");
			}
		}
		else
			printf("����������������룺\n");
	}
}

void Computer_Move(char g[row][col], int r, int c)
{
	int x;
	int y;
	printf("������\n");
	srand((unsigned int)time(NULL));
	while (1)
	{
		x = rand() % r;  //ȡ��֮��С��r
		y = rand() % c;
		if (g[x][y] == ' ')
		{
			g[x][y] = '#';
			break;
		}
	}
}

int full(char g[row][col], int r, int c)
{
	int x, y;
    for (x = 0; x < r;x++)
    {
		for (y = 0; y < c; y++)
		{
			if (g[x][y] == ' ')
			{
				return 0;
			}
		}
     } 
	return 1;
}
char winer(char g[row][col], int r, int c)//������[doge]
{
	int i;
	for (i= 0; i< r; i++)        //����
	{
		if (g[i][0] == g[i][1]&& g[i][1] == g[i][2] &&  g[i][2] != ' ')
		{
			if (g[i][0] == '*')
				return '1';
			else return '2';
		}
	}
	for (i = 0; i < r; i++)        //����
	{
		if (g[0][i] == g[1][i] && g[1][i]== g[2][i] && g[2][i]!=' ')
		{
			if (g[i][0] == '*')
				return '1';
			else return '2';
		}
	}
	if(g[0][0]==g[1][1]&& g[1][1]==g[2][2] &&g[2][2] !=' ')  //�����Խ���
	{
		if (g[i][0] == '*')
			return '1';
		else 
			return '2';
	}
	if (g[2][0] == g[1][1] && g[1][1] == g[0][2] && g[2][0] != ' ')
	{
		if (g[i][0] == '*')
				return '1';
		else 
			return '2';
	}
	if (full(g, r, c) == 1)  //�жϼ���
	{
		return '4';
	}
	return '3';
}



