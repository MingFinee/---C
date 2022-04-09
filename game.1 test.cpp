//三子棋游戏
#include <stdio.h>  
#include "game1.h"   //在game.h定义了行列，改变后面的数字可改变定义的行列数

int game1()
{
	char m;
	char g[row][col];//数组，存放输入的数据
	init_g(g, row, col); //初始化棋盘，全部空格
	p_g(g, row, col);   //打印棋盘    
	while (1)
	{
		Player_Move(g, row, col);     //玩家移动
		p_g(g, row, col);
		m=winer(g, row, col);         //判断是否赢
		                              //玩家赢--1 电脑赢--2  继续--3 平局--4
		if (m != '3')                       
		{
			break; 
		}
		printf("\n");
		Computer_Move(g, row, col);   //电脑自动									  
		p_g(g, row, col);         
		if (m !='3')
		{
			break;
		}
	}
	if(m=='1')
	{
		printf("你赢了\n");
	}
	else if (m == '2')
	{
		printf("你输了\n");
	}
	else 
	{
		printf("平局\n");
	}
	return 0;
}
int main()
{
	menu();
	int i;
	do
	{
		printf("请选择:\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:game1();
			   menu();
			   break;
		case 2:printf("退出游戏\n");
			break;
		default:printf("输入错误，请重新输入：\n");
			break;
		}
	} while (i != 2);
	return 0;
}
