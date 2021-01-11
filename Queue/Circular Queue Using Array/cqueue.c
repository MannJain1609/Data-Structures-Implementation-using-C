#include<stdio.h>
#include "cqueue.h"

void initialize(struct cqueue *q)
{
	q->front=-1;
	q->rear=-1;
	q->capacity=10;
}

void display(struct cqueue *q)
{
	if (isEmpty(q))
		printf("NULL");
	else
	{
		int i=q->front;
		while (i!=q->rear)
		{
			printf("%d ", q->arr[i]);
			i = (i+1)%q->capacity;
		}
		printf("%d", q->arr[q->rear]);
	}
	printf("\n");
}

int isEmpty(struct cqueue *q)
{
	if (q->front==-1 && q->rear==-1)
		return 1;
	return 0;
}


void insert(struct cqueue *q, int val)
{
	if (isEmpty(q))
	{
		q->front=0;
		q->rear=0;
		q->arr[q->rear]=val;
		return;
	}
	int temp=q->rear;
	q->rear=(q->rear+1)%q->capacity;
	if (q->front==q->rear)
	{
		printf("The queue is full, no insertion possible\n");
		q->rear=temp;
		return;
	}
	q->arr[q->rear]=val;
}

int delete(struct cqueue *q)
{
	if (isEmpty(q))
	{
		printf("Queue is already empty\n");
		return -1;
	}
	int del=q->arr[q->front];
	if (q->front==q->rear)
	{
		q->front=-1;
		q->rear=-1;
	}
	else
		q->front=(q->front+1)%q->capacity;
	return del;
}