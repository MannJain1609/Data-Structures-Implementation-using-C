#include<stdio.h>
#include "min_heap.h"

int main()
{
	struct min_heap h1;
	initialize(&h1);
	print_heap(&h1);
	int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
	int i;
	for (i=0; i<11; i++)
	{
		insert(&h1,arr[i]);
		print_heap(&h1);
	}
	print_heap(&h1);
	int del=delete(&h1,6);
	printf("%d", del);
	print_heap(&h1);
	int del2=delete(&h1,11);
	printf("%d", del2);
	print_heap(&h1);
	int del3=delete(&h1,3);
	printf("%d", del3);
	print_heap(&h1);	
	return 0;
}