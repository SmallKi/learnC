/*
	title : ������ת
	author: Smallk
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int reverseInt(int num);
int reverseInt1(int num);
int reverseInt2(int num);
int reverseInt3(int num);
int reverseInt4(int num,int newnum);

void main()
{
	int num;
	printf("input the number you want to reverse:\n");
	scanf("%d", &num);
	int newnum = reverseInt(num);
	int newnum1 = reverseInt1(num);
	int newnum2 = reverseInt2(num);
	int newnum3 = reverseInt3(num);
	int newnum4 = reverseInt4(num,0);

	printf("%d\n", newnum);
	printf("%d\n", newnum1);
	printf("%d\n", newnum2);
	printf("%d\n", newnum3);
	printf("%d\n", newnum4);

	system("pause");
}


//for���ѭ����ʽ
int reverseInt(int num)
{
	int newnum=0;
	//��numΪ0ʱ�����Ѿ���������ȡ��
	for (; num; num /= 10)
	{
		newnum *= 10;
		newnum += num % 10;
	}

	return newnum;
}

//while���ѭ����ʽ
int reverseInt1(int num)
{
	int newnum = 0;
	while (num) 
	{
		newnum *= 10;
		newnum += num % 10;
		num /= 10;
	}

	return newnum;
}


//do_while���ѭ����ʽ
int reverseInt2(int num)
{
	int newnum = 0;
	do 
	{
		newnum *= 10;
		newnum += num % 10;
		num /= 10;
	} while (num);

	return newnum;
}

//goto�����ʽ
int reverseInt3(int num)
{
	int newnum = 0;
A:	if (num)
	{
		newnum *= 10;
		newnum += num % 10;
		num /= 10;
		goto A;
	}

	return newnum;
}

//�ݹ���ʽ
int reverseInt4(int num, int newnum)
{
	if (num == 0)
	{
		return newnum;
	}else
	{
		newnum *= 10;
		newnum += num % 10;
		reverseInt4(num / 10, newnum);
	}
}