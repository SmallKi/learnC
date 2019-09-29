/*
	实现AI自动寻路算法
	每500毫秒AI走一步
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define N 10


int canOut = 0; //代表能否走出，1代表能走出，0代表不能走出
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
				};  //地图初始化

//移动算法
void move(char order);
//显示地图
void show();
//AI算法
int AIout(int a[10][10], int xpos, int ypos);

void main()
{
	//设置窗口名
	system("title 迷宫游戏");

	if (AIout(a, 0, 0)) {
		printf("恭喜你，游戏结束\n");
	}
	

	system("pause");
}


//显示地图和人物
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


//AI实现算法
int AIout(int a[10][10], int xpos, int ypos)
{
	//每次都将走过的路标记为3，防止算法持续走回头路，造成死循环
	a[xpos][ypos] = 3;
	show();
	Sleep(500);
	//当走到终点时，将全局变量canOut设置为1，代表已经找到了一条路，之后的递归就不要再遍历其他分支了
	if (xpos == N - 1 && ypos == N - 1)
	{
		canOut = 1;
		printf("恭喜你,走出来了\n");
		return canOut;
	}

	//这是a[xpos][ypos + 1] < 1 是因为当为1和3时都不能再走，如果写成!=1,那么需要再补一个!=3，防止走回头路
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

	//如果这几个方向都尝试过并且都走不通，就将其置0
	if (!canOut)
	{
		a[xpos][ypos] = 0;
		show();
		Sleep(500);
	}
	return canOut;
}