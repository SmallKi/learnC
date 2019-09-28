#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char info[100] = { 0 }; //提示信息
int x = 0, y = 0; //初始人物坐标
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
				};  //地图初始化

//移动算法
void move(char order);
//显示提示信息
void showInfo(char *str);
//显示地图和人物
void show();

void main()
{
	//设置窗口名
	system("title 迷宫游戏 & color 64");
	sprintf(info, "游戏开始，祝你好运"); //初始化提示语句
	a[0][0] = 5; //初始化人物
	while (1) {
		//显示地图和人物
		show();

		//显示提示信息
		showInfo(info);

		//等待用户输入
		char order = _getch();
		move(order);
		system("cls");
	}
	

	system("pause");
}

void move(char order)
{
	int flag = 1; //标记是否走动;
	switch (order)
	{
	case 'w':
		if (x != 0 && a[x - 1][y] != 1) {
			//与上方交换
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
			//与下方交换
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

	//根据是否移动来改变提示信息
	if (flag == 1) {
		sprintf(info, "继续前进吧，祝你好运！");
	}
	else {
		sprintf(info, "此路不通，换条路吧！");
	}

}

//显示提示信息
void showInfo(char *str)
{
	printf("提示：%s\n", str);
	printf("w a s d移动，5是你，2是墙\n");
}

//显示地图和人物
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
