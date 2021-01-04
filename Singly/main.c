#include<stdio.h>
#include "Linked_list.h"

void main()
{
	int pos;
	//scanf("%d", &value);
	struct node *head=NULL;
	//display_list(head);
	head=insert_at_begin(head,12);
	head=insert_at_begin(head,15);
	head=insert_at_begin(head,20);
	head=insert_at_begin(head,12);
	head=insert_at_begin(head,10);
	head=insert_at_begin(head,12);
	head=insert_at_pos(head,3,8);
	head=insert_at_pos(head,4,16);
	//head=delete_first(head);
	//head=delete_last(head);
	//printf("%d\n", count_nodes(head));
	//display_list(head);
	//head=delete_at_pos(head,0);
	//display_list(head);
	//head=delete_at_pos(head,4);
	//display_list(head);
	//head=delete_at_pos(head,2);
	//display_list(head);
	//head=delete_key(head,5);
	head=insert_at_last(head,7);
	display_list(head);
	head=delete_key(head,12);
	display_list(head);
	head=sort(head);
	display_list(head);
	printf("The key is present at %d position\n", search_key(head,10));
	printf("The key is present at %d position\n", search_key(head,25));	
}


