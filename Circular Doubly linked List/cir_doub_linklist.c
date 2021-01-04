#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cir_doub_linklist.h"

struct node * create_node(int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node)); //To save temp in memory even after function end
	temp->prev=NULL;
	temp->data=val;
	temp->next=NULL;
	return temp;
}


int count_nodes(struct node *head)
{
	if (head==NULL)
		return 0;
	struct node *temp=head->next;
	int count=1;
	while (temp!=head)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

void display_list(struct node *head)
{
	if (head==NULL)
	{
		printf("NULL\n");
		return;
	}
	struct node *temp=head;
	printf("%d->", temp->data);
	temp=temp->next;
	while (temp!=head)
	{
		printf("%d->", temp->data);
		temp=temp->next;
	}
	printf("head\n");
}


struct node * insert_at_begin(struct node *head, int val)
{
	struct node *temp=create_node(val);
	if (head==NULL)
	{
		head=temp;
		head->next=head;
		head->prev=head;
		return head;
	}
	temp->next=head;
	head->prev->next=temp;
	temp->prev=head->prev;
	head->prev=temp;
	head=temp;
	return head;
}

struct node * insert_at_last(struct node *head, int val)
{
	struct node *temp=create_node(val);
	if (head==NULL)
	{
		head=temp;
		head->next=head;
		head->prev=head;
		return head;
	}
	head->prev->next=temp;
	temp->prev=head->prev;
	head->prev=temp;
	temp->next=head;
	return head;
}


struct node * delete_first(struct node * head)
{
	if (head==NULL)
	{
		printf("The linked list is already empty");
		return head;
	}
	if (head->next==head)
		return NULL;
	struct node *temp=head;
	head=temp->next;
	head->prev=temp->prev;
	temp->prev->next=head;
	free(temp);
	return head;
}


struct node * insert_at_pos(struct node *head, int pos, int val)
{
	struct node *new=create_node(val);
	struct node *temp=head;
	if (pos<0 || pos>count_nodes(head))
	{
		printf("Invalid position '%d'\n", pos);
		return head;
	}
	int i=0;
	if (pos==0)
		return insert_at_begin(head,val);
	while (i<pos-1)
	{
		i += 1;
		temp=temp->next;
	}
	new->prev=temp;
	new->next=temp->next;
	temp->next->prev=new;
	temp->next=new;
	return head;
}


struct node * delete_last(struct node * head)
{
	if (head==NULL)
	{
		printf("The linked list is already empty");
		return head;	
	}
	if (head->next==NULL)
	{
		free(head);
		return NULL;
	}
	struct node *temp=head,*delete=head->prev;
	delete->prev->next=temp;
	temp->prev=delete->prev;
	free(delete);
	return head;
}


struct node * delete_at_pos(struct node * head, int pos)
{
	if (pos<0 || pos>count_nodes(head)-1)
	{
		printf("Invalid position '%d'\n", pos);
		return head;
	}
	int i=0;
	struct node *temp=head,*delete;
	if (pos==0)
		return delete_first(head);
	while (i<pos-1)
	{
		i++;
		temp=temp->next;
	}
	delete=temp->next;
	temp->next=delete->next;
	delete->next->prev=temp;
	free(delete);
	return head;
}


struct node * insert_at_sorted_pos(struct node * head, int val)
{
	int i=1;
	if (head==NULL)
	{
		head=create_node(val);
		return head;
	}
	if (head->data>val)
		return insert_at_begin(head,val);
	struct node *temp=head->next;
	int flag=0;
	while (temp!=head)
	{
		if (temp->data > val)
		{
			flag=1;
			head=insert_at_pos(head,i,val);
			break;
		}
		i++;
		temp=temp->next;
	}
	if (flag==0)
		head=insert_at_last(head,val);
	return head;
}


struct node *sort(struct node *head)
{
	int i=0,flag=0;
	struct node *loop=head;
	if (head==NULL)
		return head;
	while (loop->next!=head)
	{
		struct node *temp=head;
		while (temp->next!=head)
		{
			if (temp->data > temp->next->data)
			{
				flag=1;
				int samp=temp->data;
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


int search_key(struct node * head, int val)
{
	if (head->data==val)
		return 0;
	struct node *temp=head->next;
	int i=1,pos=-1;
	while (temp!=head)
	{
		if (temp->data==val)
		{
			pos=i;
			break;
		}
		i++;
		temp=temp->next;
	}
	return pos;
}
