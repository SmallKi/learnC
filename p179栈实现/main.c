//≤‚ ‘’ªΩ·ππ
#include "stack.h"

void main()
{
	STACK stack = { 0 };
	PSTACK pstack = &stack;
	//≥ı ºªØ’ª
	init(pstack);
	//—π’ª
	push(pstack, 5);
	
	for (int i = 0; i < stackSize; i++)
	{
		push(pstack, i);
	}

	for (int i = 0; i < stackSize+1; i++)
	{
		printf("top:%d\n", getTop(pstack));
		showStack(pstack);
		pop(pstack);
	}


	system("pause");
}