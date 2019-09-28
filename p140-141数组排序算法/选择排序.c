#include<stdio.h>
#include<stdlib.h>

//选择排序声明
void sortedUp(int *a);
void sortedDown(int *a);

void main()
{
	int a[5] = { 14,51,15,56,23 };
	//原始值
	printf("原始数组:\n");
	for (int i = 0; i < 5; i++)
	{
		printf(" %c:%d", i + 65, a[i]);
	}
	printf("\n\n");

	sortedUp(a,sizeof(a)/sizeof(int));
	printf("排序后数组:\n");
	for (int i = 0; i < 5; i++)
	{
		printf(" %c:%d", i + 65, a[i]);
	}
	printf("\n\n");

	sortedDown(a, sizeof(a) / sizeof(int));
	printf("排序后数组:\n");
	for (int i = 0; i < 5; i++)
	{
		printf(" %c:%d", i + 65, a[i]);
	}
	printf("\n\n");
	system("pause");
}


//选择排序实现
void sortedDown(int *a,int length) 
{
	int insert = 0;  //定义需要将每个最大值应该插入的下标值

	while (insert != length - 1) //当要插入的下标是数组的最后一个元素时，说明排序已经完成
	{
		int maxIndex = insert; //最大值的下标值,每次都初始化成要插入的位置的值
		for (int i = maxIndex+1; i < length; i++)
		{
			a[i] > a[maxIndex] ? maxIndex = i : 0;
		}

		if (insert == maxIndex);//当要插入的位置就是最大值所在的位置，什么都不做
		else        //否则，交换两者的位置 
		{
			a[insert] ^= a[maxIndex];
			a[maxIndex] ^= a[insert];
			a[insert] ^= a[maxIndex];
		}

		insert++;   //要插入的位置再向移动一位;
	}

};


//选择排序实现
void sortedUp(int *a, int length)
{
	int insert = 0;  //定义需要将每个最小值应该插入的下标值

	while (insert != length - 1) //当要插入的下标是数组的最后一个元素时，说明排序已经完成
	{
		int minIndex = insert; //最大值的下标值,每次都初始化成要插入的位置的值
		for (int i = minIndex + 1; i < length; i++)
		{
			a[i] < a[minIndex] ? minIndex = i : 0;
		}

		if (insert == minIndex);//当要插入的位置就是最小值所在的位置，什么都不做
		else        //否则，交换两者的位置 
		{
			a[insert] ^= a[minIndex];
			a[minIndex] ^= a[insert];
			a[insert] ^= a[minIndex];
		}

		insert++;   //要插入的位置再向移动一位;
	}

};


