#include<stdio.h>
#include "stack.h"

int main()
{
	struct Stack s1;
	initialise(&s1);
	push(&s1,'a');
	push(&s1,'b');

	printf("%c\n",top(&s1));
	printf("%c\n",pop(&s1));
	printf("%c\n",pop(&s1));
	printf("%c\n",pop(&s1));
	printf("%c\n",top(&s1));
	return 0;
}