#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//二分查找，num为待查找数，a是查找数组，length是数组长度
void binarySearch(int num,int *a, int length);

//拉格朗日查找
void lagrangeSearch(int num, int *a, int length);

//二分查找的递归实现
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
		printf("输入要查找的数：\n");
		scanf("%d", &search);
		binarySearch(search, a, length);
		lagrangeSearch(search, a, length);
		binarySearch1(search, a, length-1,0);
	}
	system("pause");
}

//二分查找，num为待查找数，a是查找数组，length是数组长度
void binarySearch(int num, int *a, int length)
{
	int count = 0; //记录查找几次，对比拉格朗日
	int flag = 0; //标志是否找到
	int max = length - 1;
	int min = 0;
	//int mid =  (max+min)/2 //容易溢出
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
		printf("二分查找找到了，下标为：%d，查找了%d次\n", mid, count);
	}
	else {
		printf("不存在\n");
	}
	
}

//拉格朗日查找
void lagrangeSearch(int num, int *a, int length)
{
	int count = 0; //记录查找几次，对比二分查找
	int flag = 0; //标志是否找到
	int max = length - 1;
	int min = 0;
	//int mid =  (max+min)/2 //容易溢出
	int mid;

	//当num<a[min]时，拉格朗日差值为负，无法正常判断
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
		printf("拉格朗日找到了，下标为：%d，查找了%d次\n", mid,count);
	}
	else {
		printf("不存在\n");
	}
}

//二分查找的递归实现
void binarySearch1(int num, int *a, int max, int min)
{
	
	int mid = min + (max - min) / 2;
	//出口;当num=a[mid]时，代表找到了；当min=max，而且num依然不等于a[mid]，说明没找到，同样推出
	if (num == a[mid]) 
	{
		printf("二分递归找到了，下标为：%d\n", mid);
		return;
	}
	if (min == max)
	{
		printf("不存在\n", mid);
		return;
	}


	//当值大于中间值，最小值更换为中间值+1
	if (num > a[mid])
	{
		binarySearch1(num, a, max, mid + 1);
	}
	else if(num < a[mid])
	{
		binarySearch1(num, a, mid-1, min);
	}
}
