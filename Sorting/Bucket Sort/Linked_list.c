#include<stdio.h>
#include<stdlib.h>
#include "Linked_list.h"

struct node * create_node(double val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node)); //To save temp in memory even after function end
	temp->data=val;
	temp->next=NULL;
	return temp;
}

struct node * insert(struct node *head, double val)
{
	struct node *temp=create_node(val);
	if (head!=NULL)
		temp->next=head;
	head=temp;
	return head;
}

struct node *sort(struct node *head)
{
	int i=0,flag=0;
	struct node *loop=head;
	if (head==NULL)
		return head;
	while (loop!=NULL)
	{
		struct node *temp=head;
		while (temp->next!=NULL)
		{
			if (temp->data > temp->next->data)
			{
				flag=1;
				double samp=temp->data;
				temp->data=temp->next->data;
				temp->next->data=samp;
			}
			temp=temp->next;
		}
		loop=loop->next;
		if (flag==0)
			break;
	}
	return head;
}