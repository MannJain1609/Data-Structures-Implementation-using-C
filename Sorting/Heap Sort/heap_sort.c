#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "heap.h"

void heap_sort(int [],int );
void print_array(int [], int );

int main()
{
	int arr[10],i;
	srand(time(0));
	for (i=0; i<10; i++)
		arr[i]=rand()%100;
	print_array(arr,10);
	heap_sort(arr,10);
	print_array(arr,10);
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

void print_array(int array[], int size)
{
	int i;
	for (i=0; i<size; i++)
		printf("%d ", array[i]);
	printf("\n");
}