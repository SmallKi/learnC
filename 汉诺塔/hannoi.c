#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROWS 10
#define COLUMNS 3

//初始化汉诺塔
void InitHannoi(int n);
//显示汉诺塔
void showHannoi(char,char,char);
//汉诺塔算法
void Hannoi(int num, char A, char B, char C);
//实现数组的变化
void move(char X, char Y);
//等待输入指令
void getCommand(char*);

int num[ROWS][COLUMNS] = { 0 };
void main()
{
	int quiz = 1;
	printf("input the number of Hannoi: \n");
	int a = scanf("%d", &quiz);
	InitHannoi(quiz);
	Hannoi(quiz, 'A', 'B', 'C');

}

void InitHannoi(int n)
{
	for (int i = ROWS-1; i >= 0 && n>0; i--) {
			num[i][0] = n--;
	}
}

void showHannoi(char a,char b,char c) {
	printf("\t%c\t%c\t%c\n", a, b, c);
	printf("-------------------------------------\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 3; j++) {
			printf("\t%d", num[i][j]);
		}
		printf("\n");
	}
}

void Hannoi(int num, char A, char B, char C) {
	static int count = 1;
	if (num == 1) 
	{
		printf("第%d步：%c -> %c\n",count++, A, C);
		move(A,C);
		showHannoi(A,B,C);
		getCommand("pree 'n' and 'return' to next page");
		return;
	}
	else if (num <= 0) {
		return;
	}
	else
	{
		Hannoi(num - 1, A, C, B);
		printf("第%d步：%c -> %c\n", count++, A, C);
		move(A, C);
		showHannoi(A, B, C);
		getCommand("pree 'n' and 'return' to next page");
		Hannoi(num - 1, B, A, C);
	}
}

void move(char X, char Y) 
{
	int x = X - 65;
	int y = Y - 65;
	int a = 0;
	int b = ROWS - 1;
	for (int i = 0; i < ROWS; i++) {
		if (num[i][x])
		{
			a = i;
			break;
		}
	}
	if (num[b][y] == 0) {
		b = ROWS - 1;
	}else{
		for (int i = 0; i < ROWS; i++) {
			if (num[i][y] && i!=0) {
				b = i-1;
				break;
			}
		}
	}

	//交换两个值
	num[a][x] ^= num[b][y];
	num[b][y] ^= num[a][x];
	num[a][x] ^= num[b][y];
}


void getCommand(char *str) {
	char command[100] = { 0 };
	sprintf(command, str);
	printf("%s\n", command);
	char order;
	do {
		order = getchar();
	} while (order != 'n');
}