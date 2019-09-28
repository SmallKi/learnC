#include<stdio.h>
#include<stdlib.h>

//ѡ����������
void sortedUp(int *a);
void sortedDown(int *a);

void main()
{
	int a[5] = { 14,51,15,56,23 };
	//ԭʼֵ
	printf("ԭʼ����:\n");
	for (int i = 0; i < 5; i++)
	{
		printf(" %c:%d", i + 65, a[i]);
	}
	printf("\n\n");

	sortedUp(a,sizeof(a)/sizeof(int));
	printf("���������:\n");
	for (int i = 0; i < 5; i++)
	{
		printf(" %c:%d", i + 65, a[i]);
	}
	printf("\n\n");

	sortedDown(a, sizeof(a) / sizeof(int));
	printf("���������:\n");
	for (int i = 0; i < 5; i++)
	{
		printf(" %c:%d", i + 65, a[i]);
	}
	printf("\n\n");
	system("pause");
}


//ѡ������ʵ��
void sortedDown(int *a,int length) 
{
	int insert = 0;  //������Ҫ��ÿ�����ֵӦ�ò�����±�ֵ

	while (insert != length - 1) //��Ҫ������±�����������һ��Ԫ��ʱ��˵�������Ѿ����
	{
		int maxIndex = insert; //���ֵ���±�ֵ,ÿ�ζ���ʼ����Ҫ�����λ�õ�ֵ
		for (int i = maxIndex+1; i < length; i++)
		{
			a[i] > a[maxIndex] ? maxIndex = i : 0;
		}

		if (insert == maxIndex);//��Ҫ�����λ�þ������ֵ���ڵ�λ�ã�ʲô������
		else        //���򣬽������ߵ�λ�� 
		{
			a[insert] ^= a[maxIndex];
			a[maxIndex] ^= a[insert];
			a[insert] ^= a[maxIndex];
		}

		insert++;   //Ҫ�����λ�������ƶ�һλ;
	}

};


//ѡ������ʵ��
void sortedUp(int *a, int length)
{
	int insert = 0;  //������Ҫ��ÿ����СֵӦ�ò�����±�ֵ

	while (insert != length - 1) //��Ҫ������±�����������һ��Ԫ��ʱ��˵�������Ѿ����
	{
		int minIndex = insert; //���ֵ���±�ֵ,ÿ�ζ���ʼ����Ҫ�����λ�õ�ֵ
		for (int i = minIndex + 1; i < length; i++)
		{
			a[i] < a[minIndex] ? minIndex = i : 0;
		}

		if (insert == minIndex);//��Ҫ�����λ�þ�����Сֵ���ڵ�λ�ã�ʲô������
		else        //���򣬽������ߵ�λ�� 
		{
			a[insert] ^= a[minIndex];
			a[minIndex] ^= a[insert];
			a[insert] ^= a[minIndex];
		}

		insert++;   //Ҫ�����λ�������ƶ�һλ;
	}

};


