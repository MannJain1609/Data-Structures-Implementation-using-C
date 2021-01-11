#include<stdio.h>
#include<stdlib.h>
#include "cqueue.h"

void initialize(struct cqueue *q)
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

void display(struct cqueue *q)
{
	if (q->count==0)
		printf("NULL\n");
	else
	{
		struct node *temp=q->front;
		printf("%d ",temp->data);
		temp=temp->next;
		while (temp!=q->front)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

void insert(struct cqueue *q, int val)
{
	if (q->count==0)
	{
		q->front=create_node(val);
		q->rear=q->front;
		q->rear->next=q->front;
		q->count++;
		return;
	}
	struct node *new=create_node(val);
	q->rear->next=new;
	new->next=q->front;
	q->rear=new;
	q->count++;
}

int delete(struct cqueue *q)
{
	if (q->count==0)
	{
		printf("Queue is already empty\n");
		return -1;
	}
	struct node *temp=q->front;
	int del=temp->data;
	if (q->count==1)
	{
		q->front=NULL;
		q->rear=NULL;
		q->count=0;
		free(temp);
		return del;
	}
	q->front=temp->next;
	q->rear->next=q->front;
	free(temp);
	q->count--;
	return del;
}


int isEmpty(struct cqueue *q)
{
	if (q->count==0)
		return 1;
	return 0;
}