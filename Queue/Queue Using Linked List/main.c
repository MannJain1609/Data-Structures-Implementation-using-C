#include<stdio.h>
#include "queue.h"

int main()
{
	struct queue q1;
	initialize(&q1);
	display(&q1);
	insert(&q1,5);
	display(&q1);
	insert(&q1,2);
	display(&q1);
	insert(&q1,3);
	display(&q1);
	insert(&q1,7);
	display(&q1);
	printf("The deleted element is %d\n", delete(&q1));
	display(&q1);
	printf("The deleted element is %d\n", delete(&q1));
	display(&q1);
	insert(&q1,1);
	display(&q1);
	printf("The deleted element is %d\n", delete(&q1));
	display(&q1);
	printf("The deleted element is %d\n", delete(&q1));
	display(&q1);
	printf("The deleted element is %d\n", delete(&q1));
	display(&q1);
	printf("The deleted element is %d\n", delete(&q1));
	display(&q1);
	return 0;
}