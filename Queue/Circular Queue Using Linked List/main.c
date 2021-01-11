#include<stdio.h>
#include "cqueue.h"

int main()
{
	struct cqueue q1;
	initialize(&q1);
	display(&q1);
	insert(&q1,2);
	display(&q1);
	insert(&q1,5);
	display(&q1);
	insert(&q1,0);
	display(&q1);
	insert(&q1,7);
	display(&q1);
	printf("The deleted element is %d\n", delete(&q1));
	display(&q1);
	printf("The deleted element is %d\n", delete(&q1));
	display(&q1);
	insert(&q1,3);
	display(&q1);
	printf("The deleted element is %d\n", delete(&q1));
	display(&q1);
	printf("The deleted element is %d\n", delete(&q1));
	display(&q1);
	printf("The deleted element is %d\n", delete(&q1));
	display(&q1);
	printf("The deleted element is %d\n", delete(&q1));
	display(&q1);
	insert(&q1,1);
	display(&q1);
	return 0;
}