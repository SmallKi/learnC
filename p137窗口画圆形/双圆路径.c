#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>

#define PI 3.1415926  //����PI
#define R 200   //Բ�İ뾶  

void windowDoubleCircle(char* className, char* windowName);

void main() 
{
	char className[100] = { 0 };
	char windowName[100] = { 0 };
	printf("�����봰�ڵ�����:\n");
	int n1 = scanf("%s", className);
	printf("�����봰�ڵı�����:\n");
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
	int flag = 1;  //��־���ĸ�Բ
	int x, y;
	HWND win = FindWindowA(className, windowName);

	
	if (win) {
		while (1) {
			//�����ر�ע�⣬��Ļ��xy����������ѧ�Ĳ�̫һ��������໭ͼ���
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
			//���ﵽ�ཻ��ʱ�����нǶȵĸı�
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
		printf("δ�ҵ�����");
	}
}