#include<stdio.h>
#include<limits.h>
#include "min_heap.h"

void initialize(struct min_heap *h)
{
	h->size=0;
	h->arr[0]=INT_MAX;
}

void print_heap(struct min_heap *h)
{
	int i;
	if (h->size==0)
	{
		printf("The heap is empty");
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

int isLeaf_node(struct min_heap *h, int i)
{
	if (i>h->size/2)
		return 1;
	return 0;
}

int get_min_index(struct min_heap *h, int i)
{
	int min_index=i;
	int rc=right_child(i);
	int lc=left_child(i);
	if (rc<=h->size && h->arr[rc]<h->arr[min_index])
		min_index=rc;
	if (lc<=h->size && h->arr[lc]<h->arr[min_index])
		min_index=lc;
	return min_index;
}

void min_heapify(struct min_heap *h, int i)
{
	if (isLeaf_node(h,i))
		return;
	int ind=get_min_index(h,i);
	int temp;
	if (ind!=i)
	{
		temp=h->arr[i];
		h->arr[i]=h->arr[ind];
		h->arr[ind]=temp;
		min_heapify(h,ind);
	}
}

void build_heap(struct min_heap *h)
{
	int i;
	for(i=h->size/2; i>0; i--)
	{
		min_heapify(h,i);
	}
}

void heapDecreaseKey(struct min_heap *h, int i, int val)
{
	if (val>h->arr[i])
	{
		printf("Error!!\n");
		return;
	}	
	while(i>1 && val<h->arr[parent(i)])
	{
		h->arr[i]=h->arr[parent(i)];
		i=parent(i);
	}	
	h->arr[i]=val;
}

void insert(struct min_heap *h, int val)
{
	h->size++;
	h->arr[h->size]=INT_MAX;
	heapDecreaseKey(h,h->size,val);
}

int delete(struct min_heap *h, int i)
{
	if (i>h->size)
	{
		printf("The index does not exist :(\n");
		return -1;
	}
	int del=h->arr[i];
	if (h->arr[i]<h->arr[h->size])
	{
		h->arr[i]=h->arr[h->size];
		h->size--;
		min_heapify(h,i);
	}
	else
	{
		heapDecreaseKey(h,i,h->arr[h->size]);
		h->size--;
	}
	return del;
}

int extract_min(struct min_heap *h)
{
	int min=h->arr[1];
	h->arr[1]=h->arr[h->size];
	h->size--;
	min_heapify(h,1);
	return min;
}

int height_of_heap(struct min_heap *h)
{
	double x= log (h->size)/log (2);
	int y=round(x);
	if (x>y)
		y=y+1;
	return y;
}