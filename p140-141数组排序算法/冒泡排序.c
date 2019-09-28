#include<stdio.h>
#include<stdlib.h>
void selectedUp(int *,int);
void selectedDown(int *, int);

void main()
{
	int a[5] = { 1,23,3,44,2};
	printf("排序前:\n");
	for (int i = 0; i < 5; i++) {
		printf("%c:%d ", i + 65, a[i]);
	}
	printf("\n\n");

	//顺序排列
	selectedUp(a,sizeof(a)/sizeof(int));
	printf("排序后:\n");
	for (int i = 0; i < 5; i++) {
		printf("%c:%d ", i + 65, a[i]);
	}
	printf("\n\n");

	//逆序排列
	selectedDown(a, sizeof(a) / sizeof(int));
	printf("排序后:\n");
	for (int i = 0; i < 5; i++) {
		printf("%c:%d ", i + 65, a[i]);
	}
	printf("\n\n");

	printf("%d", test);
	system("pause");
}

void selectedUp(int * a, int length)
{
	int flag = 0;   //定义一个标志，当没有产生交换时，flag为0  

	//五个数需要沉底4次，可以得出n个数需要沉底n-1次
	for (int j = 1; j < length; j++) {
		for (int i = 0; i < length -j; i++)
		{
			//前一个数大于后一个数就交换位置，让最大的数沉底
			if (a[i] > a[i + 1])
			{
				//交换位置
				a[i] ^= a[i + 1];
				a[i + 1] ^= a[i];
				a[i] ^= a[i + 1];
				//标志本次循环产生了交换
				flag = 1;
			}

		}
		if (flag == 0) break; //当没有产生交换时，退出循环
		//重置标志
		flag = 0;
	}
	
}

void selectedDown(int * a, int length)
{
	int flag = 0;   //定义一个标志，当没有产生交换时，flag为0  

	//五个数需要沉底4次，可以得出n个数需要沉底n-1次
	for (int j = 1; j < length; j++) {
		for (int i = 0; i < length - j; i++)
		{
			//前一个数小于后一个数就交换位置，让最大的数沉底
			if (a[i] < a[i + 1])
			{
				//交换位置
				a[i] ^= a[i + 1];
				a[i + 1] ^= a[i];
				a[i] ^= a[i + 1];
				//标志本次循环产生了交换
				flag = 1;
			}

		}
		if (flag == 0) break; //当没有产生交换时，退出循环
							  //重置标志
		flag = 0;
	}

}