#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("***********************\n");
	printf("*****   1. play   *****\n");
	printf("*****   0. exit   *****\n");
	printf("***********************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 }; //��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = { 0 }; //����Ų�����׵���Ϣ
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0'); //��ʼ��Ϊȫ0
	InitBoard(show, ROWS, COLS, '*'); //��ʼ��Ϊȫ*

	//��ӡ����
	//DisplayBoard(mine, ROW, COL); //ֻ�ô�ӡ�м䲿�����̣�ʵ���в��ܴ�ӡ��
	DisplayBoard(show, ROW, COL); //ֻ�ô�ӡ�м䲿������

	//������
	SetMine(mine, ROW, COL);
    //DisplayBoard(mine, ROW, COL);

	//�Ų���
	 //�Ų�����mine�������Ϣ��������show����ȥ
	FindMine(mine, show, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game (); //ɨ����Ϸ
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
        	printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}