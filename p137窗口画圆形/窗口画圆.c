#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>

#define PI 3.1415926  //定义PI
#define R 200   //圆的半径  

void windowCircle(char* className, char* windowName);

void main()
{
	char className[100] = { 0 };
	char windowName[100] = { 0 };
	printf("请输入窗口的标题名:\n");
	int n1 = scanf("%[^\n]", windowName);
	getchar();
	printf("请输入窗口的类名:\n");
	int n2 = scanf("%[^\n]", className);
	

	windowCircle(className, windowName);
}



void windowCircle(char* className, char* windowName) 
{
	//圆心的xy坐标
	int px = 400;
	int py = 300;
	int angle = 0; //角度
	HWND win = FindWindowA(className, windowName);
	if (win) {
		while (1)
		{
			int x = px + R * cos(angle * PI / 180);
			int y = py + R * sin(angle * PI / 180);

			SetWindowPos(win, 0, x, y, 0, 0, 1);
			angle++;
			if (angle == 360) {
				angle = 0;
			}
		}

	}
	else {
		printf("没有查找到相应程序窗口");
	}
}