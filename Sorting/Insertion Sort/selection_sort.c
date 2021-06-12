#include<stdio.h>
#include<stdlib.h>

//Time Complexity O(n^2)
void selection_sort(int [], int );
void print_array(int [], int );

int main()
{
	int a[10],i;
	for (i=0; i<10; i++)
	{
		a[i]=rand()%100;
	}
	print_array(a,10);
	selection_sort(a,10);
	print_array(a,10);
}

void selection_sort(int array[], int size)
{
	int i=0;
	int min=array[i];
	int j,index=i;
	while(i<size-1)
	{
		min=array[i];
		index=i;
		for (j=i+1; j<size; j++)
		{
			if (array[j]<min)
			{
				index=j;
				min=array[j];
			}
		}
		array[index]=array[i];
		array[i]=min;
		i++;
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
