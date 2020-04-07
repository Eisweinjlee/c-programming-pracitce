#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,num;
	int count = 0;
	int *ptr = NULL; // must do
	
	do
	{
		printf("input an integer (-1 to stop): ");
		scanf("%d", &num);
		count++;
		
		ptr = (int*) realloc(ptr, count * sizeof(int));
		if(ptr == NULL) exit(1);
		
		ptr[count-1] = num;
	} while(num != -1);
	
	printf("The integers are:\n");
	for(i=0;i<count-1;i++)
	{
		printf("%d ", ptr[i]);
	}
	
	free(ptr);
	
	return 0;
}
