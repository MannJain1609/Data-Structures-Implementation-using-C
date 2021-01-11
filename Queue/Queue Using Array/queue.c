#include<stdio.h>
#include "queue.h"

void initialize(struct queue *q)
{
	q->front=-1;
	q->rear=-1;
	q->capacity=10;
}

void display_queue(struct queue *q)
{
	if (isEmpty(q))
		printf("NULL");
	else
	{
		int i;
		for (i=q->front; i<=q->rear; i++)
		{
			printf("%d ", q->arr[i]);
		}
	}
	printf("\n");
}

int isEmpty(struct queue *q)
{
	if (q->front==-1 && q->rear==-1)
		return 1;
	return 0;
}


void insert(struct queue *q, int val)
{
	if (isEmpty(q))
	{
		q->front=0;
		q->rear=0;
		q->arr[q->rear]=val;
		return;
	}
	if (q->rear>=q->capacity-1)
	{
		printf("The queue is full, no insertion possible\n");
		return;
	}
	q->rear++;
	q->arr[q->rear]=val;
}


int delete(struct queue *q)
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
		q->front++;
	return del;
}

int isFull(struct queue *q)
{
	if (q->front==0 && q->rear==q->capacity-1)
		return 1;
	return 0;
}