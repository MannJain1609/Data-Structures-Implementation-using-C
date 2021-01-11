#include<stdio.h>
#include<stdlib.h>
#include "Linked_list.h"

struct node * create_node(int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node)); //To save temp in memory even after function end
	temp->data=val;
	temp->next=NULL;
	return temp;
}


struct node * insert_at_begin(struct node *head, int val)
{
	struct node *temp=create_node(val);
	if (head!=NULL)
		temp->next=head;
	head=temp;
	return head;
}


struct node * delete_first(struct node * head)
{
	struct node *temp=head;
	if (head==NULL)
	{
		printf("The linked list is already empty");
		return head;
	}
	head=temp->next;
	free(temp);
	return head;
}

