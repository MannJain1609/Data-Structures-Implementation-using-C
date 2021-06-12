#include<stdio.h>
#include<stdlib.h>

//Time Complexity O(n^2)
void bubble_sort(int [], int );
void print_array(int [], int );

int main()
{
	int a[10],i;
	for (i=0; i<10; i++)
	{
		a[i]=rand()%100;
	}
	print_array(a,10);
	bubble_sort(a,10);
	print_array(a,10);
}

void bubble_sort(int array[], int size)
{
	int flag=0,i,j;
	for (i=0; i<size; i++)
	{
		flag=0;
		for (j=0; j<size-i-1; j++)
		{
			if (array[j]>array[j+1])
			{
				flag=1;
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
		if (flag==0)
			break;
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
