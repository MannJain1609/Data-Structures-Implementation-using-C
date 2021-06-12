#include<stdio.h>
#include<limits.h>
#include<math.h>
#include "heap.h"

void initialize(struct max_heap *h)
{
	h->size=0;
	h->arr[0]=INT_MIN;
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


int extract_max(struct max_heap *h)
{
	int max=h->arr[1];
	h->arr[1]=h->arr[h->size];
	h->arr[h->size]=max;
	h->size--;
	max_heapify(h,1);
	return max;
}
