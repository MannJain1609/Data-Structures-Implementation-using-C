#include "stack.h"
#include<stdio.h>

void push(struct Stack *s,char val)
{
	if (isFull(s))
	{
		printf("Stack Overflow\n");
		return;
	}
	s->arr[++(s->top_index)]=val;
}

char pop(struct Stack *s)
{
	if (isEmpty(s))
	{
		printf("Stack Underflow\n");
		return '0';
	}
	return s->arr[(s->top_index)--];
}

char top(struct Stack *s)
{
	if (isEmpty(s))
	{
		printf("Stack Underflow\n");
		return '0';
	}
	return s->arr[s->top_index];
}

int isEmpty(struct Stack *s)
{
	if (s->top_index==-1)
		return 1;
	return 0;
}

int isFull(struct Stack *s)
{
	if (s->top_index==s->capacity-1)
		return 1;
	return 0;
}

void initialise(struct Stack *s)
{
	s->capacity = 100;
	s->top_index = -1;
}
