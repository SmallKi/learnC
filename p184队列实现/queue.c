#include "queue.h"

//初始化队列
void init(PQUEUE queue)
{
	queue->head = 0;
	queue->tail = 0; //尾元法
	memset(queue->queueList, 0, QSIZE * sizeof(int));
	printf("初始化成功\n");
}

//判定是否为空
int isEmpty(const PQUEUE queue)
{
	if (queue->tail == queue->head)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//判定是否满
int isFull(const PQUEUE queue)
{
	if (queue->tail == QSIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//获取出队元素
int getTail(const PQUEUE queue)
{
	if (!isEmpty(queue))
	{
		return queue->queueList[queue->tail - 1];
	}
	else
	{
		printf("队列为空\n");
		return 0;
	}
}

//入队
void enQueue(PQUEUE queue, int num)
{
	if (!isFull(queue))
	{
		for (int i = queue->tail; i > queue->head; i--)
		{
			queue->queueList[i] = queue->queueList[i - 1];
		}
		queue->queueList[queue->head] = num;
		queue->tail++;
	}
	else
	{
		printf("队列已满，无法插入\n");
	}
}

//出队
int deQueue(PQUEUE queue)
{
	if (!isEmpty(queue))
	{
		queue->tail--;
		return queue->queueList[queue->tail];
	}
	else
	{
		printf("队列为空，无法弹出\n");
		return 0;
	}
}

//显示队列
void show(const PQUEUE queue)
{
	if (isEmpty(queue))
	{
		printf("空列表\n");
		
	}
	else
	{
		for (int i = 0; i < getLength(queue); i++)
		{
			printf("%d\n", queue->queueList[i]);
		}
	}
	
}

//获取队列长度
int getLength(const PQUEUE queue)
{
	return queue->tail - queue->head;
}
