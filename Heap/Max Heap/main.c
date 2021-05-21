#include<stdio.h>
#include "max_heap.h"

void heap_sort(int [],int );

int main()
{
	struct max_heap h1;
	initialize(&h1);
	//print_heap(&h1);
	int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
	int i;
	for (i=0; i<11; i++)
	{
		insert(&h1,arr[i]);
		print_heap(&h1);
	}
	print_heap(&h1);
	int a=height_of_heap(&h1);
	printf("%d\n", a);
	/*int del=delete(&h1,6);
	printf("%d", del);
	print_heap(&h1);
	int del2=delete(&h1,11);
	printf("%d", del2);
	print_heap(&h1);
	int del3=delete(&h1,3);
	printf("%d", del3);
	print_heap(&h1);
	heap_sort(arr, 11);
	int j;
	for (j=0; j<11; j++)
		printf("%d ", arr[j]);*/
	return 0;
}

void heap_sort(int array[], int size)
{
	struct max_heap h;
	h=build_heap(array, size);
	int i,x;
	while(h.size>0)
		x=extract_max(&h);
	for (i=0; i<size; i++)
		array[i]=h.arr[i+1];
}