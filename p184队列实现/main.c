#include "queue.h"

void main()
{
	QUEUE queue = { 0 };
	PQUEUE pQueue = &queue;
	init(pQueue);
	for (int i = 0; i < 100; i++)
	{
		enQueue(pQueue, i);
	}
	show(pQueue);
	int length;
	printf("length:%d\n", length = getLength(pQueue));
	for (int i = 0; i < length; i++)
	{
		printf("µ¯³öÔªËØ£º%d\n", getTail(pQueue));
		deQueue(pQueue);
	}

	show(pQueue);

	system("pause");
}