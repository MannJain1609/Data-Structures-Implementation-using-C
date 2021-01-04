#include<stdio.h>
#include<stdlib.h>
#include "cir_linked_list.h"

struct node * create_node(int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node)); //To save temp in memory even after function end
	temp->data=val;
	temp->next=NULL;
	return temp;
}

int count_nodes(struct node *head)
{
	struct node *temp=head;
	if (head==NULL)
		return 0;
	int count=1;
	temp=temp->next;
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
		return head;
	}
	temp->next=head;
	struct node *loop=head;
	while (loop->next!=head)
		loop=loop->next;
	loop->next=temp;
	head=temp;
	return head;
}


struct node * insert_at_last(struct node *head, int val)
{
	struct node *new=create_node(val);	
	struct node *temp=head,*loop=head;
	if (head==NULL)
	{
		head=new;
		head->next=head;
		return head;
	}
	while (loop->next!=head)
		loop=loop->next;
	loop->next=new;
	new->next=temp;
	return head;
}


struct node * insert_at_pos(struct node *head, int pos, int val)
{
	struct node *new=create_node(val);
	struct node *temp=head,*prev,*forw;
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
	prev=temp;
	forw=temp->next;
	prev->next=new;
	new->next=forw;
	return head;
}


struct node * delete_first(struct node * head)
{
	if (head==NULL)
	{
		printf("The linked list is already empty");
		return head;
	}
	struct node *temp=head,*ff=head;
	while (temp->next!=head)
		temp=temp->next;
	head=head->next;
	temp->next=head;
	free(ff);
	return head;
}

struct node * delete_last(struct node * head)
{
	if (head==NULL)
	{
		printf("The linked list is already empty");
		return head;	
	}
	if (head->next==head)
	{
		head=NULL;
		return head;
	}
	struct node *temp=head;
	while (temp->next->next!=head)
	{
		temp=temp->next;
	}
	struct node *demo=temp->next;
	temp->next=head;
	free(demo);
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
	free(delete);
	return head;
}

struct node * delete_key(struct node * head, int key)
{
	if (head==NULL)
	{
		printf("Linked list is empty :)");
		return head;
	}
	if (head->data==key)
		return delete_first(head);
	struct node *temp=head;
	int i=1;
	temp=temp->next;
	while (temp!=head)
	{
		if (temp->next->data==key)
			head=delete_at_pos(head,i+1);
		i++;
		temp=temp->next;
	}
	return head;
}

struct node * insert_at_sorted_pos(struct node * head, int val)
{
	if (head==NULL)
	{
		head=create_node(val);
		head->next=head;
		return head;
	}
	if (head->data>val)
		return insert_at_begin(head,val);
	struct node *temp=head->next;
	int flag=0;
	int i=1;
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