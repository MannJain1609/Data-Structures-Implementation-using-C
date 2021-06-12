#include<stdio.h>
#include<stdlib.h>

//only applicable for non negative integers
//Time Complexity O(n)
void radix_sort(int [],int [],int ,int );
void counting_sort(int [],int [],int ,int ,int);
int nth_digit(int , int );
void copy_array(int [], int [], int );
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
	radix_sort(a,b,10,99);
	print_array(b,10);
}

void radix_sort(int array[], int result[], int size, int max)
{
	int i=1;
	int max_digits=0;
	int demo=max;
	while(demo>0)
	{
		demo=demo/10;
		max_digits++;
	}
	while(i<=max_digits)
	{
		counting_sort(array,result,size,max,i);
		i++;
	}
}

int nth_digit(int a, int i)
{
	int k=1;
	while(k<i)
	{
		a=a/10;
		k++;
	}
	int r=a%10;
	return r;
}

void copy_array(int source[], int destination[], int size)
{
	int i;
	for(i=0; i<size; i++)
		destination[i]=source[i];
}

void counting_sort(int array[],int result[],int size,int max,int i)
{
	int x,j,k,m;
	int arr[max+1];
	for(x=0; x<max+1; x++)
			arr[x]=0;
	for(j=0; j<size; j++)
		arr[nth_digit(array[j],i)]++;
	for (k=1; k<max+1; k++)
		arr[k]=arr[k]+arr[k-1];
	for (m=size-1; m>=0; m--)
	{
		result[arr[nth_digit(array[m],i)]-1]=array[m];
		arr[nth_digit(array[m],i)]--;
	}
	copy_array(result,array,size);
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