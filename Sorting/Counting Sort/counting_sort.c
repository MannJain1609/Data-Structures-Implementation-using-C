#include<stdio.h>
#include<stdlib.h>

//only applicable for non negative integers
//Time Complexity O(n)
void counting_sort(int [],int [],int ,int );
void print_array(int [], int );

int main()
{
	int a[10],i,b[10];
	srand(time(0));
	for (i=0; i<10; i++)
	{
		a[i]=rand()%100;
	}
	print_array(a,10);
	counting_sort(a,b,10,99);
	print_array(b,10);
}

void counting_sort(int array[],int result[], int size,int max)
{
	int arr[max+1];
	int x,i,j,k;
	//initializing the array to zero
	for (x=0; x<max+1; x++)
		arr[x]=0;
	for (i=0; i<size; i++)
		arr[array[i]]++;
	//making a cumulative array
	for (j=1; j<max+1; j++)
		arr[j]=arr[j]+arr[j-1];
	//creating a new sorted array result
	for (k=0; k<size; k++)
	{
		result[arr[array[k]]-1]=array[k];
		arr[array[k]]--;
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