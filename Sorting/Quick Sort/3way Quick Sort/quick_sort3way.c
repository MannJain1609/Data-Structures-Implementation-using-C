#include<stdio.h>
#include<stdlib.h>

//Time Complexity O(n*log n)

void quick_sort(int [], int ,int );
int* partition(int [],int ,int );
void print_array(int [], int );

int main()
{
	int a[10],i;
	srand(time(0));
	for (i=0; i<10; i++)
	{
		a[i]=rand()%10;
	}
	print_array(a,10);
	quick_sort(a,0,9);
	print_array(a,10);
}

void quick_sort(int array[], int begin, int end)
{
	if (end>begin)
	{
		int* pos=partition(array,begin,end);
		quick_sort(array,begin,pos[0]-1);
		quick_sort(array,pos[1]+1,end);
	}
}

int* partition(int array[],int begin,int end)
{
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
	int k=i;
	while(array[k]==array[i])
		k++;
	k--;
	static int arr[2];
	arr[0]=i;
	arr[1]=k;
	return arr;
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
