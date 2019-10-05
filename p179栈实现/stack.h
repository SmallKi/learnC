#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define stackSize 10

//����ջ�ṹ
typedef struct 
{
	int list[stackSize];  //ջ����
	int top;  //ͷ��ָ��
}STACK,* PSTACK;

//ջ�ĳ�ʼ��
void init(PSTACK stack);

//��ȡջ��ͷ��Ԫ��
int getTop(const PSTACK stack);

//�����Ƿ�Ϊ��
int isEmpty(const PSTACK stack);

//�����Ƿ�ջ��
int isFull(const PSTACK stack);

//ѹ��ջ
void push(PSTACK stack, int num);

//����ջ
void pop(PSTACK stack);

//��ʾջԪ��
void showStack(const PSTACK stack);