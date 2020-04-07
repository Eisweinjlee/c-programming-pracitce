#include<stdio.h>
#include<stdlib.h>

int global_uninit_var;
int global_init_var1 = 520;
int global_init_var2 = 888;

void func(void);

void func(void)
{
	;
}

int main()
{
	int local_var1;
	int local_var2;
	
	static int static_uninit_var;
	static int static_init_var = 678;
	
	char *str1 = "I love C!";
	char *str2 = "You are right!";
	
	int *malloc_var = (int*) malloc(sizeof(int));
	
	printf("addr of func -> %p\n", func);
	printf("addr of str1 -> %p\n", str1);
	printf("addr of str2 -> %p\n\n", str2);
	
	printf("addr of global_init_var1 -> %p\n", &global_init_var1);
	printf("addr of global_init_var2 -> %p\n", &global_init_var2);
	printf("addr of static_init_var -> %p\n\n", &static_init_var);
	
	printf("addr of global_uninit_var -> %p\n", &global_uninit_var);
	printf("addr of static_uninit_var -> %p\n\n", &static_uninit_var);
	
	printf("addr of malloc_var -> %p\n", malloc_var);
	printf("addr of local_var1 -> %p\n", &local_var1);
	printf("addr of local_var2 -> %p\n\n", &local_var2);
	
	
	// heap and stack
	int* ptr1 = NULL; // local values
	int* ptr2 = NULL; // in stack
	
	ptr1 = (int*)malloc(sizeof(int)); // malloc spaces
	ptr2 = (int*)malloc(sizeof(int)); // in heap
	
	printf("stack: %p --> %p\n", &ptr1, &ptr2);
	printf("heap:%p --> %p\n\n", ptr1, ptr2);
	
	ptr1 = (int*)realloc(ptr1, 20*sizeof(int)); // not big enough for 20 int
	printf("After realloc,\nptr1: %p, ptr2: %p\n", ptr1, ptr2);
	
	free(ptr1);
	free(ptr2);
	
	return 0;
}
