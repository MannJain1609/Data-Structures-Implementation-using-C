#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

void initialize(struct queue *q)
{
	q->front=NULL;
	q->rear=NULL;
	q->count=0;
}

struct node * create_node(int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node)); //To save temp in memory even after function end
	temp->data=val;
	temp->next=NULL;
	return temp;
}

void display(struct queue *q)
{
	if (isEmpty(q)==0)
	{
		struct node *temp=q->front;
		while (temp!=NULL)
		{
			printf("%d ", temp->data);
			temp=temp->next;
		}
	}
	printf("NULL\n");
}

int isEmpty(struct queue *q)
{
	if (q->count==0)
		return 1;
	return 0;
}

void insert(struct queue *q, int val)
{
	if (isEmpty(q))
	{
		q->front=create_node(val);
		q->rear=q->front;
		q->count++;
		return;
	}
	struct node *temp=create_node(val);
	q->rear->next=temp;
	q->rear=temp;
	q->count++;
}


int delete(struct queue *q)
{
	if (q->count==0)
	{
		printf("Queue is already empty\n");
		return -1;
	}
	struct node *temp=q->front;
	int del=temp->data;
	q->front=q->front->next;
	if (q->count==1)
		q->rear=NULL;
	q->count--;
	free(temp);
	return del;
}