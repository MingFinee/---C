//��������Ϸ
#include <stdio.h>  
#include "game1.h"   //��game.h���������У��ı��������ֿɸı䶨���������

int game1()
{
	char m;
	char g[row][col];//���飬������������
	init_g(g, row, col); //��ʼ�����̣�ȫ���ո�
	p_g(g, row, col);   //��ӡ����    
	while (1)
	{
		Player_Move(g, row, col);     //����ƶ�
		p_g(g, row, col);
		m=winer(g, row, col);         //�ж��Ƿ�Ӯ
		                              //���Ӯ--1 ����Ӯ--2  ����--3 ƽ��--4
		if (m != '3')                       
		{
			break; 
		}
		printf("\n");
		Computer_Move(g, row, col);   //�����Զ�									  
		p_g(g, row, col);         
		if (m !='3')
		{
			break;
		}
	}
	if(m=='1')
	{
		printf("��Ӯ��\n");
	}
	else if (m == '2')
	{
		printf("������\n");
	}
	else 
	{
		printf("ƽ��\n");
	}
	return 0;
}
int main()
{
	menu();
	int i;
	do
	{
		printf("��ѡ��:\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:game1();
			   menu();
			   break;
		case 2:printf("�˳���Ϸ\n");
			break;
		default:printf("����������������룺\n");
			break;
		}
	} while (i != 2);
	return 0;
}
