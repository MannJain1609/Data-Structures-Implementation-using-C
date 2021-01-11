#include<stdio.h>
#include "stack.h"

int main()
{
	struct Stack s1;
	initialize(&s1);
	print_stack(&s1);
	push(&s1,12);
	print_stack(&s1);
	push(&s1,5);
	print_stack(&s1);
	push(&s1,2);
	print_stack(&s1);
	printf("The deleted item is:%d\n", pop(&s1));
	print_stack(&s1);
	printf("The deleted item is:%d\n", pop(&s1));
	print_stack(&s1);
	printf("The deleted item is:%d\n", pop(&s1));
	print_stack(&s1);
	printf("The deleted item is:%d\n", pop(&s1));
	print_stack(&s1);
	push(&s1,1);
	print_stack(&s1);
	push(&s1,5);
	print_stack(&s1);
	push(&s1,185);
	print_stack(&s1);
	push(&s1,-3);
	print_stack(&s1);
	printf("No. of elements=%d\n", count_of_elements(&s1));
	//printf("stack is %d\n", isEmpty(&s1));
	return 0;
}