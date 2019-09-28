#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char info[100] = { 0 }; //��ʾ��Ϣ
int x = 0, y = 0; //��ʼ��������
int a[10][10] = { 
	{0,1,0,0,0,0,1,0,0,1},
	{ 0,1,0,0,0,1,0,0,0,1 },
	{ 0,1,0,0,0,1,1,0,0,1 },
	{ 0,0,0,1,0,0,0,0,0,1 },
	{ 0,0,0,0,0,1,1,0,1,0 },
	{ 0,1,0,0,0,1,1,0,0,1 },
	{ 0,1,0,1,0,1,0,1,0,0 },
	{ 0,1,1,0,0,1,1,0,0,1 },
	{ 0,0,0,1,0,0,1,0,0,0 },
	{ 0,1,0,0,0,1,1,0,0,1 }
				};  //��ͼ��ʼ��

//�ƶ��㷨
void move(char order);
//��ʾ��ʾ��Ϣ
void showInfo(char *str);
//��ʾ��ͼ������
void show();

void main()
{
	//���ô�����
	system("title �Թ���Ϸ & color 64");
	sprintf(info, "��Ϸ��ʼ��ף�����"); //��ʼ����ʾ���
	a[0][0] = 5; //��ʼ������
	while (1) {
		//��ʾ��ͼ������
		show();

		//��ʾ��ʾ��Ϣ
		showInfo(info);

		//�ȴ��û�����
		char order = _getch();
		move(order);
		system("cls");
	}
	

	system("pause");
}

void move(char order)
{
	int flag = 1; //����Ƿ��߶�;
	switch (order)
	{
	case 'w':
		if (x != 0 && a[x - 1][y] != 1) {
			//���Ϸ�����
			a[x - 1][y] ^= a[x][y];
			a[x][y] ^= a[x - 1][y];
			a[x - 1][y] ^= a[x][y];
			x--;
		}
		else {
			flag = 0;
		}
		break;

	case 's':
		if (x != 9 && a[x + 1][y] != 1) {
			//���·�����
			a[x][y] ^= a[x + 1][y];
			a[x + 1][y] ^= a[x][y];
			a[x][y] ^= a[x + 1][y];
			x++;
		}
		else {
			flag = 0;
		}
		break;

	case 'a':
		if (y != 0 && a[x][y - 1] != 1) {
			a[x][y] ^= a[x][y - 1];
			a[x][y - 1] ^= a[x][y];
			a[x][y] ^= a[x][y - 1];
			y--;
		}
		else {
			flag = 0;
		}
		break;

	case 'd':
		if (y != 9 && a[x][y + 1] != 1) {
			a[x][y] ^= a[x][y + 1];
			a[x][y + 1] ^= a[x][y];
			a[x][y] ^= a[x][y + 1];
			y++;
		}
		else {
			flag = 0;
		}
		break;
	default:
		;
	}

	//�����Ƿ��ƶ����ı���ʾ��Ϣ
	if (flag == 1) {
		sprintf(info, "����ǰ���ɣ�ף����ˣ�");
	}
	else {
		sprintf(info, "��·��ͨ������·�ɣ�");
	}

}

//��ʾ��ʾ��Ϣ
void showInfo(char *str)
{
	printf("��ʾ��%s\n", str);
	printf("w a s d�ƶ���5���㣬2��ǽ\n");
}

//��ʾ��ͼ������
void show()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}
