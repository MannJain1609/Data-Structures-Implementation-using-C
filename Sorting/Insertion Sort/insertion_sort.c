#include<stdio.h>
#include<stdlib.h>

//Time Complexity O(n^2)
void insertion_sort(int [], int );
void print_array(int [], int );

int main()
{
	int a[10],i;
	for (i=0; i<10; i++)
	{
		a[i]=rand()%100;
	}
	print_array(a,10);
	insertion_sort(a,10);
	print_array(a,10);
}

void insertion_sort(int array[], int size)
{
	int i=1,j;
	for(i=1; i<size; i++)
	{
		j=i;
		while (j>0)
		{
			if (array[j]>=array[j-1])
				break;
			int temp=array[j];
			array[j]=array[j-1];
			array[j-1]=temp;
			j--;
		}
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
