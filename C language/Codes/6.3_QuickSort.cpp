#include<stdio.h>

void quick_sort(int array[], int left, int right)
{
	int i = left, j = right;
	int temp;
	int pivot;
	
	pivot = array[(left+right)/2];
	
	while(i <= j)
	{
		// from left to right, find those values bigger than pivot
		while(array[i] < pivot)
		{
			i++;
		}
		//from right to left, find those values smaller than pivot
		while(array[j] > pivot)
		{
			j--;
		}
		// if i<=j, switch the i-th and j-th element
		if (i<=j)
		{
			temp = array[i]; array[i] = array[j]; array[j] = temp;
			i++; j--;
		}
	}
	
	if (left<j)
	{
		quick_sort(array, left, j);
	}
	
	if (i<right)
	{
		quick_sort(array, i, right);
	}
}

int main(void)
{
	int n,i;
	int array[100]={0};
	
	printf("How many numbers to be sorted?\n");
	scanf("%d", &n);
	
	printf("Give me %d int values for sorting:\n", n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &array[i]);
	}
	
	quick_sort(array, 0, n-1);
	
	printf("The sorted result:\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d ", array[i]);
	}
	
	return 0;
}
