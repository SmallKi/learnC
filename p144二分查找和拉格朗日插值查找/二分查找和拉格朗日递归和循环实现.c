#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//���ֲ��ң�numΪ����������a�ǲ������飬length�����鳤��
void binarySearch(int num,int *a, int length);

//�������ղ���
void lagrangeSearch(int num, int *a, int length);

//���ֲ��ҵĵݹ�ʵ��
void binarySearch1(int num, int *a, int max, int min);

void main()
{
	int num = 1;
	int a[1024] = { 0 };
	int length = sizeof(a) / sizeof(int);
	for (int i = 0; i < length; i++)
	{
		a[i] = num++;
	}
	while (1)
	{
		int search;
		printf("����Ҫ���ҵ�����\n");
		scanf("%d", &search);
		binarySearch(search, a, length);
		lagrangeSearch(search, a, length);
		binarySearch1(search, a, length-1,0);
	}
	system("pause");
}

//���ֲ��ң�numΪ����������a�ǲ������飬length�����鳤��
void binarySearch(int num, int *a, int length)
{
	int count = 0; //��¼���Ҽ��Σ��Ա���������
	int flag = 0; //��־�Ƿ��ҵ�
	int max = length - 1;
	int min = 0;
	//int mid =  (max+min)/2 //�������
	int mid;

	if (num >= a[min] && num <= a[max])
	{
		while (min <= max)
		{
			count++;
			mid = min + (max - min) / 2;
			if (num > a[mid])
			{
				min = mid + 1;
			}
			else if (num < a[mid])
			{
				max = mid - 1;
			}
			else
			{
				flag = 1;
				break;
			}
		}
	}
	

	if (flag == 1)
	{
		printf("���ֲ����ҵ��ˣ��±�Ϊ��%d��������%d��\n", mid, count);
	}
	else {
		printf("������\n");
	}
	
}

//�������ղ���
void lagrangeSearch(int num, int *a, int length)
{
	int count = 0; //��¼���Ҽ��Σ��Աȶ��ֲ���
	int flag = 0; //��־�Ƿ��ҵ�
	int max = length - 1;
	int min = 0;
	//int mid =  (max+min)/2 //�������
	int mid;

	//��num<a[min]ʱ���������ղ�ֵΪ�����޷������ж�
	if (num >= a[min] && num <= a[max])
	{
		while (min <= max)
		{
			count++;
			mid = min + (max - min) * 1.0 *(num - a[min]) / (a[max] - a[min]);
			if (num > a[mid])
			{
				min = mid + 1;
			}
			else if (num < a[mid])
			{
				max = mid - 1;
			}
			else
			{
				flag = 1;
				break;
			}
		}
	}
	

	if (flag == 1)
	{
		printf("���������ҵ��ˣ��±�Ϊ��%d��������%d��\n", mid,count);
	}
	else {
		printf("������\n");
	}
}

//���ֲ��ҵĵݹ�ʵ��
void binarySearch1(int num, int *a, int max, int min)
{
	
	int mid = min + (max - min) / 2;
	//����;��num=a[mid]ʱ�������ҵ��ˣ���min=max������num��Ȼ������a[mid]��˵��û�ҵ���ͬ���Ƴ�
	if (num == a[mid]) 
	{
		printf("���ֵݹ��ҵ��ˣ��±�Ϊ��%d\n", mid);
		return;
	}
	if (min == max)
	{
		printf("������\n", mid);
		return;
	}


	//��ֵ�����м�ֵ����Сֵ����Ϊ�м�ֵ+1
	if (num > a[mid])
	{
		binarySearch1(num, a, max, mid + 1);
	}
	else if(num < a[mid])
	{
		binarySearch1(num, a, mid-1, min);
	}
}
