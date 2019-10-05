#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define stackSize 10

//定义栈结构
typedef struct 
{
	int list[stackSize];  //栈数组
	int top;  //头部指针
}STACK,* PSTACK;

//栈的初始化
void init(PSTACK stack);

//获取栈的头部元素
int getTop(const PSTACK stack);

//检验是否为空
int isEmpty(const PSTACK stack);

//检验是否栈满
int isFull(const PSTACK stack);

//压入栈
void push(PSTACK stack, int num);

//弹出栈
void pop(PSTACK stack);

//显示栈元素
void showStack(const PSTACK stack);