#include<stdio.h>
#include<stdlib.h>

//Time Complexity O(n*log n)

void merge_sort(int [], int ,int );
void merge(int [], int , int , int );
void print_array(int [], int );

int main()
{
	int a[10],i;
	for (i=0; i<10; i++)
	{
		a[i]=rand()%100;
	}
	print_array(a,10);
	merge_sort(a,0,9);
	print_array(a,10);
}

void merge_sort(int array[], int begin, int end)
{
	if (end>begin)
	{
		int mid=(end+begin)/2;
		merge_sort(array,begin,mid);
		merge_sort(array,mid+1,end);
		merge(array,begin,mid,end);
	}
}

void merge(int array[], int begin, int mid, int end)
{
	int left_array[mid-begin+1],right_array[end-mid];
	int x,y,p=0,q=0;
	for (x=begin; x<=mid; x++)
		left_array[p++]=array[x];
	for (y=mid+1; y<=end; y++)
		right_array[q++]=array[y];
	int i=0,j=0,k=begin;
	while(i<left_size && j<right_size)
	{
		if (left_array[i]<right_array[j])
		{
			array[k]=left_array[i];
			i++;
		}
		else
		{
			array[k]=right_array[j];
			j++;
		}
		k++;
	}
	//adding remaining numbers
	while(i<left_size)
	{
		array[k]=left_array[i];
		k++;
		i++;
	}
	while(j<right_size)
	{
		array[k]=right_array[j];
		k++;
		j++;
	}
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
