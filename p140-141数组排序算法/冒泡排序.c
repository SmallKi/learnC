#include<stdio.h>
#include<stdlib.h>
void selectedUp(int *,int);
void selectedDown(int *, int);

void main()
{
	int a[5] = { 1,23,3,44,2};
	printf("����ǰ:\n");
	for (int i = 0; i < 5; i++) {
		printf("%c:%d ", i + 65, a[i]);
	}
	printf("\n\n");

	//˳������
	selectedUp(a,sizeof(a)/sizeof(int));
	printf("�����:\n");
	for (int i = 0; i < 5; i++) {
		printf("%c:%d ", i + 65, a[i]);
	}
	printf("\n\n");

	//��������
	selectedDown(a, sizeof(a) / sizeof(int));
	printf("�����:\n");
	for (int i = 0; i < 5; i++) {
		printf("%c:%d ", i + 65, a[i]);
	}
	printf("\n\n");

	printf("%d", test);
	system("pause");
}

void selectedUp(int * a, int length)
{
	int flag = 0;   //����һ����־����û�в�������ʱ��flagΪ0  

	//�������Ҫ����4�Σ����Եó�n������Ҫ����n-1��
	for (int j = 1; j < length; j++) {
		for (int i = 0; i < length -j; i++)
		{
			//ǰһ�������ں�һ�����ͽ���λ�ã�������������
			if (a[i] > a[i + 1])
			{
				//����λ��
				a[i] ^= a[i + 1];
				a[i + 1] ^= a[i];
				a[i] ^= a[i + 1];
				//��־����ѭ�������˽���
				flag = 1;
			}

		}
		if (flag == 0) break; //��û�в�������ʱ���˳�ѭ��
		//���ñ�־
		flag = 0;
	}
	
}

void selectedDown(int * a, int length)
{
	int flag = 0;   //����һ����־����û�в�������ʱ��flagΪ0  

	//�������Ҫ����4�Σ����Եó�n������Ҫ����n-1��
	for (int j = 1; j < length; j++) {
		for (int i = 0; i < length - j; i++)
		{
			//ǰһ����С�ں�һ�����ͽ���λ�ã�������������
			if (a[i] < a[i + 1])
			{
				//����λ��
				a[i] ^= a[i + 1];
				a[i + 1] ^= a[i];
				a[i] ^= a[i + 1];
				//��־����ѭ�������˽���
				flag = 1;
			}

		}
		if (flag == 0) break; //��û�в�������ʱ���˳�ѭ��
							  //���ñ�־
		flag = 0;
	}

}