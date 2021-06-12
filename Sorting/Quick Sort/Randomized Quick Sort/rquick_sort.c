#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Time Complexity O(n*log n)

void quick_sort(int [], int ,int );
int partition(int [],int ,int );
void print_array(int [], int );

int main()
{
	int a[10],i;
	for (i=0; i<10; i++)
	{
		a[i]=rand()%100;
	}
	print_array(a,10);
	quick_sort(a,0,9);
	print_array(a,10);
}

void quick_sort(int array[], int begin, int end)
{
	if (end>begin)
	{
		int pos=partition(array,begin,end);
		quick_sort(array,begin,pos-1);
		quick_sort(array,pos+1,end);
	}
}

int partition(int array[],int begin,int end)
{
	srand(time(0));
	int index=rand()%(end-begin+1)+begin;
	int demo=array[index];
	array[index]=array[end];
	array[end]=demo;
	int pivot=array[end];
	int i=begin-1,j=begin;
	for (j=begin; j<end; j++)
	{
		if (array[j]<pivot)
		{
			i++;
			int temp=array[i];
			array[i]=array[j];
			array[j]=temp;
		}
	}
	i++;
	int temp=array[i];
	array[i]=array[end];
	array[end]=temp;
	return i;
}

void print_array(int array[], int size)
{
	int i;
	for (i=0; i<size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}