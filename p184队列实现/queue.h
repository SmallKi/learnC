#ifndef QUEUEH
#define QUEUEH
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define QSIZE 100

//����������ݽṹ
typedef struct 
{
	int queueList[QSIZE];
	int head; //ͷ����ǣ�����
	int tail; //β����ǣ�����
}QUEUE,*PQUEUE;

//��ʼ������
void init(PQUEUE queue);

//�ж��Ƿ�Ϊ��
int isEmpty(const PQUEUE queue);

//�ж��Ƿ���
int isFull(const PQUEUE queue);

//��ȡ����Ԫ��
int getTail(const PQUEUE queue);

//���
void enQueue(PQUEUE queue, int num);

//����
int deQueue(PQUEUE queue);

//��ʾ����
void show(const PQUEUE queue);

//��ȡ���г���
int getLength(const PQUEUE queue);

#endif