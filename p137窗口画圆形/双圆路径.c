#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>

#define PI 3.1415926  //定义PI
#define R 200   //圆的半径  

void windowDoubleCircle(char* className, char* windowName);

void main() 
{
	char className[100] = { 0 };
	char windowName[100] = { 0 };
	printf("请输入窗口的类名:\n");
	int n1 = scanf("%s", className);
	printf("请输入窗口的标题名:\n");
	int n2 = scanf("%s", windowName);

	windowDoubleCircle(className, windowName);


}

void windowDoubleCircle(char* className, char* windowName) 
{
	int pfx = 300;
	int pfy = 200;
	int psx = 300 + 2 * R;
	int psy = pfy;
	int angle = 0;
	int flag = 1;  //标志在哪个圆
	int x, y;
	HWND win = FindWindowA(className, windowName);

	
	if (win) {
		while (1) {
			//这是特别注意，屏幕的xy坐标轴与数学的不太一样，建议多画图理解
			if (flag)
			{
				x = pfx + R * cos(angle * PI / 180);
				y = pfy - R * sin(angle * PI / 180);
			}
			else {
				x = psx + R * cos(angle * PI / 180);
				y = psy + R * sin(angle * PI / 180);
			}

			SetWindowPos(win, 0, x, y, 0, 0, 1);

			angle++;
			//当达到相交点时，进行角度的改变
			if (angle == 360 && flag == 1)
			{
				angle = 180;
				flag = 0;
			}
			else if (angle == 540 && flag == 0) {
				angle = 0;
				flag = 1;
			}

		}
	}
	else {
		printf("未找到窗口");
	}
}