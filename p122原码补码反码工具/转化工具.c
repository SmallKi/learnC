#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void strf(int num, char str[33]);
void stry(int num, char str[33]);
void strb(int num, char str[33]);

void main()
{
	const int NUM = -1;
	/*int num;
	scanf("%d", &num);*/
	char str1[100] = { 0 };
	char str2[100] = { 0 };
	char str3[100] = { 0 };
	stry(NUM, str1);
	strf(NUM, str2);
	strb(NUM, str3);

	printf("%s\n%s\n%s\n", str1, str2, str3);

	system("pause");
}


//补码工具
void strb(int num, char str[33])
{

	unsigned int data = 1 << 31;
	for (int i = 0; i < 32; i++)
	{
		if ((num & data) == 0)
		{
			str[i] = '0';
		}
		else {
			str[i] = '1';
		}

		num <<= 1;
	}
}

//反码工具
void strf(int num, char str[33])
{

	unsigned int data = 1 << 31;
	if (num < 0) {
		num -= 1;
	}
	for (int i = 0; i < 32; i++)
	{
		if ((num & data) == 0)
		{
			str[i] = '0';
		}
		else {
			str[i] = '1';
		}

		num <<= 1;
	}
}

//源码工具
void stry(int num, char str[33])
{

	unsigned int data = 1 << 31;
	if (num < 0) {
		num = num - 1;
		num = ~num;
		num = num | data;
	}
	for (int i = 0; i < 32; i++)
	{
		if ((num & data) == 0)
		{
			str[i] = '0';
		}
		else {
			str[i] = '1';
		}

		num <<= 1;
	}
}