#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr = NULL;
	int num, i;
	
	printf("How many integer you want: ");
	scanf("%d",&num);
	
	ptr = (int*)malloc(num * sizeof(int));
	
	for(i=0;i<num;i++){
		printf("The %d-th integer: ", i+1);
		scanf("%d", ptr+i);
	}
	
	printf("The integers you gave:\n");
	for(i=0;i<num;i++){
		printf("%d ", *(ptr+i));
	}
	printf("\n");
	
	free(ptr);
	
	return 0;
}
