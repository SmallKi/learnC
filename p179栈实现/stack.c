#include "stack.h"

//ջ�ĳ�ʼ��
void init(PSTACK stack)
{
	stack->top = 0; //ʹ��βԪ��������ͷ������ָ�����һ��Ԫ�صĺ�һ����ַ
	memset(stack->list, 0, stackSize*sizeof(int));
}

//��ȡջ��ͷ��Ԫ��
int getTop(const PSTACK stack)
{
	if (!isEmpty(stack))
	{
		return stack->list[stack->top - 1];
	}
	else
	{
		printf("û��ջԪ��\n");
		return 0;
	}
}

//�����Ƿ�Ϊ��
int isEmpty(const PSTACK stack)
{
	if (stack->top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//�����Ƿ�ջ��
int isFull(const PSTACK stack)
{
	if (stack->top == stackSize)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//ѹ��ջ
void push(PSTACK stack, int num)
{
	if (!isFull(stack))
	{
		stack->list[stack->top] = num;
		stack->top++;
	}
	else
	{
		printf("\"%d\"��ջʧ�ܣ�ջ��\n",num);
	}
}

//����ջ
void pop(PSTACK stack)
{
	if (!isEmpty(stack))
	{
		stack->top--;
	}
	else
	{
		printf("����ջʧ�ܣ�ջ�ѿ�\n");
	}
}


//��ʾջԪ��
void showStack(const PSTACK stack)
{
	if (isEmpty(stack))
	{
		printf("��\n");
	}
	else
	{
		for (int i = 0; i < stack->top; i++)
		{
			printf("%3d ", stack->list[i]);
		}
	}
	
	printf("\n");
}