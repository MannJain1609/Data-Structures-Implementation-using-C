#include<stdio.h>
#include "cir_linked_list.h"

void main()
{
	//int value;
	//scanf("%d", &value);
	struct node *head=NULL;
	printf("%d\n", count_nodes(head));
	head=insert_at_begin(head,70);
	display_list(head);
	head=insert_at_begin(head,10);
	display_list(head);
	head=insert_at_begin(head,5);
	display_list(head);
	head=insert_at_last(head,2);
	display_list(head);
	head=insert_at_last(head,3);
	display_list(head);
	head=insert_at_last(head,2);
	display_list(head);
	head=insert_at_pos(head,0,12);
	display_list(head);
	head=insert_at_pos(head,7,0);
	display_list(head);
	head=insert_at_pos(head,3,6);
	display_list(head);
	head=delete_first(head);
	//printf("%d\n", count_nodes(head));
	display_list(head);
	head=delete_first(head);
	display_list(head);
	head=delete_last(head);
	display_list(head);
	head=delete_at_pos(head,0);
	display_list(head);
	head=delete_at_pos(head,2);
	display_list(head);
	head=delete_at_pos(head,3);
	display_list(head);
	head=delete_at_pos(head,3);
	display_list(head);
	head=insert_at_begin(head,6);
	head=insert_at_pos(head,2,6);
	display_list(head);
	head=delete_key(head,6);
	display_list(head);
	head=insert_at_last(head,6);
	display_list(head);
	head=delete_key(head,6);
	display_list(head);
	//head=insert_at_sorted_pos(head,15);
	//head=insert_at_sorted_pos(head,12);
	head=sort(head);
	display_list(head);
}