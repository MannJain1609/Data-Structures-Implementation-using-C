#include<stdio.h>
#include<stdlib.h>
#include "cir_doub_linklist.h"

void main()
{
	struct node *head=NULL;
	printf("%d\n", count_nodes(head));
	display_list(head);
	head=insert_at_last(head,3);
	display_list(head);
	head=delete_first(head);
	display_list(head);
	head=insert_at_begin(head,2);
	display_list(head);
	head=insert_at_sorted_pos(head,5);
	display_list(head);
	head=insert_at_sorted_pos(head,25);
	display_list(head);
	head=insert_at_sorted_pos(head,1);
	display_list(head);
	head=insert_at_sorted_pos(head,8);
	display_list(head);
	head=insert_at_pos(head,5,7);
	display_list(head);
	/*head=delete_first(head);
	display_list(head);
	head=delete_last(head);
	display_list(head);
	head=delete_at_pos(head,2);
	display_list(head);
	head=delete_key(head,8);*/
	head=sort(head);
	display_list(head);
	printf("key->%d\n", search_key(head,7));
	printf("%d\n", count_nodes(head));
}