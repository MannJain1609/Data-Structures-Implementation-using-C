#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
//#include "Linked_list.h"

void initialize(struct Stack *s)
{
	s->head=NULL;
	s->count=0;
}

void push(struct Stack *s, int val)
{
	s->head=insert_at_begin(s->head,val);
	s->count++;
}

void print_stack(struct Stack *s)
{
	struct node *temp=s->head;
	while (temp!=NULL)
	{
		printf("%d->", temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}


int pop(struct Stack *s)
{
	if (s->count==0)
		return -1;
	int popped=s->head->data;
	s->head=delete_first(s->head);
	s->count--;
	return popped;
}

int count_of_elements(struct Stack *s)
{
	return s->count;
}


int isEmpty(struct Stack *s)
{
	if (s->count==0)
		return 1;
	return 0;
}