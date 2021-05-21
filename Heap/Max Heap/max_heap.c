#include<stdio.h>
#include<limits.h>
#include<math.h>
#include "max_heap.h"

void initialize(struct max_heap *h)
{
	h->size=0;
	h->arr[0]=INT_MIN;
}

void print_heap(struct max_heap *h)
{
	int i;
	if (h->size==0)
	{
		printf("The heap is empty\n");
		return;
	}
	for (i=1; i<=h->size; i++)
		printf("%d ", h->arr[i]);
	printf("\n");
}

int parent(int i)
{
	return i/2;
}

int left_child(int i)
{
	return 2*i;
}

int right_child(int i)
{
	return 2*i+1;
}

int isLeaf_node(struct max_heap *h, int i)
{
	if (i>h->size/2)
		return 1;
	return 0;
}

int get_max_index(struct max_heap *h, int i)
{
	int max_index=i;
	int rc=right_child(i);
	int lc=left_child(i);
	if (rc<=h->size && h->arr[rc]>h->arr[max_index])
		max_index=rc;
	if (lc<=h->size && h->arr[lc]>h->arr[max_index])
		max_index=lc;
	return max_index;
}

void max_heapify(struct max_heap *h, int i)
{
	if (isLeaf_node(h,i))
		return;
	int ind=get_max_index(h,i);
	int temp;
	if (ind!=i)
	{
		temp=h->arr[i];
		h->arr[i]=h->arr[ind];
		h->arr[ind]=temp;
		max_heapify(h,ind);
	}
}

struct max_heap build_heap(int array[], int size)
{
	struct max_heap h;
	initialize(&h);
	int i;
	for (i=0; i<size; i++)
		h.arr[i+1]=array[i];
	h.size=size;
	int j;
	for (j=h.size/2; j>0; j--)
		max_heapify(&h,j);
	return h;
}

void heapIncreaseKey(struct max_heap *h, int i, int val)
{
	if (val<h->arr[i])
	{
		printf("Error!!\n");
		return;
	}	
	while(i>1 && val>h->arr[parent(i)])
	{
		h->arr[i]=h->arr[parent(i)];
		i=parent(i);
	}	
	h->arr[i]=val;
}

void insert(struct max_heap *h, int val)
{
	h->size++;
	h->arr[h->size]=INT_MIN;
	heapIncreaseKey(h,h->size,val);
}

int delete(struct max_heap *h, int i)
{
	if (i>h->size)
	{
		printf("The index does not exist :(\n");
		return -1;
	}
	int del=h->arr[i];
	if (h->arr[i]>h->arr[h->size])
	{
		h->arr[i]=h->arr[h->size];
		h->size--;
		max_heapify(h,i);
	}
	else
	{
		heapIncreaseKey(h,i,h->arr[h->size]);
		h->size--;
	}
	return del;
}

int extract_max(struct max_heap *h)
{
	int max=h->arr[1];
	h->arr[1]=h->arr[h->size];
	h->arr[h->size]=max;
	h->size--;
	max_heapify(h,1);
	return max;
}

int heap_size(struct max_heap *h)
{
	return h->size;
}

int height_of_heap(struct max_heap *h)
{
	double x= log (h->size)/log (2);
	int y=round(x);
	if (x>y)
		y=y+1;
	return y;
}