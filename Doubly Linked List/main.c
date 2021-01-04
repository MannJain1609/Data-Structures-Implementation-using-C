#include<stdio.h>
#include<stdlib.h>
#include "doubly_linklist.h"

void main()
{
	struct node *head=NULL;
	display_list(head);
	printf("%d\n", count_nodes(head));
	head=insert_at_last(head,5);
	display_list(head);
	head=delete_last(head);
	display_list(head);
	head=insert_at_begin(head,2);
	head=insert_at_begin(head,22);
	head=insert_at_begin(head,12);
	head=insert_at_last(head,8);
	display_list(head);
	head=insert_at_pos(head,0,15);
	display_list(head);
	head=insert_at_pos(head,2,0);
	display_list(head);
	head=delete_at_pos(head,count_nodes(head)-1);
	display_list(head);
	head=delete_at_pos(head,0);
	display_list(head);
	head=delete_at_pos(head,2);
	display_list(head);
	head=delete_first(head);
	display_list(head);
	printf("%d\n", count_nodes(head));
	head=sort(head);
	display_list(head);
	head=insert_at_sorted_pos(head,5);
	display_list(head);
	head=insert_at_sorted_pos(head,3);
	display_list(head);
	display_reverse(head);
}