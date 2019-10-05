#include "queue.h"

//��ʼ������
void init(PQUEUE queue)
{
	queue->head = 0;
	queue->tail = 0; //βԪ��
	memset(queue->queueList, 0, QSIZE * sizeof(int));
	printf("��ʼ���ɹ�\n");
}

//�ж��Ƿ�Ϊ��
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

//�ж��Ƿ���
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

//��ȡ����Ԫ��
int getTail(const PQUEUE queue)
{
	if (!isEmpty(queue))
	{
		return queue->queueList[queue->tail - 1];
	}
	else
	{
		printf("����Ϊ��\n");
		return 0;
	}
}

//���
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
		printf("�����������޷�����\n");
	}
}

//����
int deQueue(PQUEUE queue)
{
	if (!isEmpty(queue))
	{
		queue->tail--;
		return queue->queueList[queue->tail];
	}
	else
	{
		printf("����Ϊ�գ��޷�����\n");
		return 0;
	}
}

//��ʾ����
void show(const PQUEUE queue)
{
	if (isEmpty(queue))
	{
		printf("���б�\n");
		
	}
	else
	{
		for (int i = 0; i < getLength(queue); i++)
		{
			printf("%d\n", queue->queueList[i]);
		}
	}
	
}

//��ȡ���г���
int getLength(const PQUEUE queue)
{
	return queue->tail - queue->head;
}
