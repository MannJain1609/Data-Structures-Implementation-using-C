#include<stdio.h>
#include<stdlib.h>
#include "Linked_list.h"

//Time Complexity O(n)

void bucket_sort(double [],int );
void print_array(double [], int );

int main()
{
	double a[10],b[10];
	srand(time(0));
	int i;
	for (i=0; i<10; i++)
	{
		a[i]=(double)(rand()%100)/100;
	}
	print_array(a,10);
	bucket_sort(a,10);
	print_array(a,10);
	return 0;
}

void bucket_sort(double array[],int size)
{
	struct node *bucket[10];
	int s;
	for(s=0; s<10; s++)
		bucket[s]=NULL;
	int i=0;
	for(i=0; i<size; i++)
	{
		int x=(array[i]*100)/10;
		bucket[x]=insert(bucket[x], array[i]);
	}	
	int j=0;
	for(j=0; j<10; j++)
	{
		bucket[j]=sort(bucket[j]);
	}
	int k=0,y=0;
	for(k=0; k<10; k++)
	{
		while(bucket[k]!=NULL)
		{
			array[y]=bucket[k]->data;
			bucket[k]=bucket[k]->next;
			y++;
		}
	}
}

void print_array(double array[], int size)
{
	int i;
	for (i=0; i<size; i++)
	{
		printf("%0.2f ", array[i]);
	}
	printf("\n");
}