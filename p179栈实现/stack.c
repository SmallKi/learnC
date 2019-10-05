#include "stack.h"

//栈的初始化
void init(PSTACK stack)
{
	stack->top = 0; //使用尾元法来定义头部，即指向最后一个元素的后一个地址
	memset(stack->list, 0, stackSize*sizeof(int));
}

//获取栈的头部元素
int getTop(const PSTACK stack)
{
	if (!isEmpty(stack))
	{
		return stack->list[stack->top - 1];
	}
	else
	{
		printf("没有栈元素\n");
		return 0;
	}
}

//检验是否为空
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

//检验是否栈满
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

//压入栈
void push(PSTACK stack, int num)
{
	if (!isFull(stack))
	{
		stack->list[stack->top] = num;
		stack->top++;
	}
	else
	{
		printf("\"%d\"入栈失败，栈满\n",num);
	}
}

//弹出栈
void pop(PSTACK stack)
{
	if (!isEmpty(stack))
	{
		stack->top--;
	}
	else
	{
		printf("弹出栈失败，栈已空\n");
	}
}


//显示栈元素
void showStack(const PSTACK stack)
{
	if (isEmpty(stack))
	{
		printf("空\n");
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