#ifndef QUEUEH
#define QUEUEH
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define QSIZE 100

//定义队列数据结构
typedef struct 
{
	int queueList[QSIZE];
	int head; //头部标记，进队
	int tail; //尾部标记，出队
}QUEUE,*PQUEUE;

//初始化队列
void init(PQUEUE queue);

//判定是否为空
int isEmpty(const PQUEUE queue);

//判定是否满
int isFull(const PQUEUE queue);

//获取出队元素
int getTail(const PQUEUE queue);

//入队
void enQueue(PQUEUE queue, int num);

//出队
int deQueue(PQUEUE queue);

//显示队列
void show(const PQUEUE queue);

//获取队列长度
int getLength(const PQUEUE queue);

#endif