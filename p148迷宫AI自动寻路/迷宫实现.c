/*
	ʵ��AI�Զ�Ѱ·�㷨
	ÿ500����AI��һ��
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define N 10


int canOut = 0; //�����ܷ��߳���1�������߳���0�������߳�
int a[10][10] = { 
	{0,1,0,0,0,0,1,0,0,1},
	{ 0,1,0,0,0,1,0,0,0,1 },
	{ 0,1,1,0,1,1,1,0,0,1 },
	{ 0,0,0,1,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,1,1,0,0 },
	{ 0,1,1,0,0,1,0,1,0,1 },
	{ 0,1,0,1,0,1,0,0,1,0 },
	{ 0,1,1,0,0,1,1,0,0,1 },
	{ 0,0,1,1,0,0,0,0,0,0 },
	{ 0,1,1,0,0,1,1,0,0,0 }
				};  //��ͼ��ʼ��

//�ƶ��㷨
void move(char order);
//��ʾ��ͼ
void show();
//AI�㷨
int AIout(int a[10][10], int xpos, int ypos);

void main()
{
	//���ô�����
	system("title �Թ���Ϸ");

	if (AIout(a, 0, 0)) {
		printf("��ϲ�㣬��Ϸ����\n");
	}
	

	system("pause");
}


//��ʾ��ͼ������
void show()
{
	printf("\n---------------------------------\n");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}


//AIʵ���㷨
int AIout(int a[10][10], int xpos, int ypos)
{
	//ÿ�ζ����߹���·���Ϊ3����ֹ�㷨�����߻�ͷ·�������ѭ��
	a[xpos][ypos] = 3;
	show();
	Sleep(500);
	//���ߵ��յ�ʱ����ȫ�ֱ���canOut����Ϊ1�������Ѿ��ҵ���һ��·��֮��ĵݹ�Ͳ�Ҫ�ٱ���������֧��
	if (xpos == N - 1 && ypos == N - 1)
	{
		canOut = 1;
		printf("��ϲ��,�߳�����\n");
		return canOut;
	}

	//����a[xpos][ypos + 1] < 1 ����Ϊ��Ϊ1��3ʱ���������ߣ����д��!=1,��ô��Ҫ�ٲ�һ��!=3����ֹ�߻�ͷ·
	if (ypos != N - 1 && a[xpos][ypos + 1] < 1 && canOut == 0)
	{
		AIout(a, xpos, ypos + 1);
	}
	if (xpos != N - 1 && a[xpos + 1][ypos] < 1 && canOut == 0 )
	{
		AIout(a, xpos + 1, ypos);
	}
	if (ypos != 0 && a[xpos][ypos - 1] < 1 && canOut == 0)
	{
		AIout(a, xpos, ypos - 1);
	}

	if (xpos != 0 && a[xpos - 1][ypos] < 1 && canOut == 0)
	{
		AIout(a, xpos-1, ypos);
	}

	//����⼸�����򶼳��Թ����Ҷ��߲�ͨ���ͽ�����0
	if (!canOut)
	{
		a[xpos][ypos] = 0;
		show();
		Sleep(500);
	}
	return canOut;
}