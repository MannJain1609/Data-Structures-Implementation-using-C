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

int count_nodes(struct node *head)
{
	struct node *temp=head;
	int count=0;
	while (temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

struct node * insert_at_begin(struct node *head, int val)
{
	struct node *temp=create_node(val);
	if (head!=NULL)
		temp->next=head;
	head=temp;
	return head;
}

void display_list(struct node *head)
{
	struct node *temp=head;
	while (temp!=NULL)
	{
		printf("%d->", temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

struct node * insert_at_last(struct node *head, int val)
{
	struct node *new=create_node(val);	
	struct node *temp=head;
	if (head==NULL)
	{
		head=new;
		return head;
	}
	while (temp->next!=NULL)
		temp=temp->next;
	temp->next=new;
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
	if (head==NULL && pos==0)
	{
		head=new;
		return head;
	}
	int i=0;
	if (pos==0)
	{
		new->next=head;
		head=new;
		return head;
	}
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


struct node * insert_at_sorted_pos(struct node * head, int val)
{
	int i=0;
	if (head==NULL)
	{
		head=create_node(val);
		return head;
	}
	struct node *temp=head;
	int flag=0;
	while (temp!=NULL)
	{
		if (temp->data > val)
		{
			flag=1;
			if (i==0)
			{
				head=insert_at_begin(head,val);
				break;
			}
			else
			{
				head=insert_at_pos(head,i,val);
				break;
			}
		}
		i++;
		temp=temp->next;
	}
	if (flag==0)
		head=insert_at_last(head,val);
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
	struct node *temp=head;
	while (temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	struct node *demo=temp->next;
	temp->next=NULL;
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
	if (head==NULL)
	{
		printf("The linked list is empty, nothing to delete");
		return head;
	}
	int i=0;
	struct node *temp=head,*delete;
	if (pos==0)
	{
		delete=head;
		head=head->next;
		free(delete);
		return head;
	}
	while (i<pos-1)
	{
		i++;
		temp=temp->next;
	}
	delete=temp->next;
	temp->next=temp->next->next;
	free(delete);
	return head;
}

struct node * delete_key(struct node * head, int key)
{
	struct node *temp=head;
	int i=0;
	while (temp!=NULL)
	{
		if (temp->data==key)
		{
			head=delete_at_pos(head,i);
			break;
		}
		i++;
		temp=temp->next;
	}
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
	struct node *temp=head;
	int i=0,pos=-1;
	while (temp!=NULL)
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