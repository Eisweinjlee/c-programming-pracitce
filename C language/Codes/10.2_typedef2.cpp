#include<stdio.h>

typedef int (*PTR_TO_FUN)(int,int); 
// define a function pointer. the pointed function has 2 int augs.

int add(int,int);
int sub(int,int);

int calc(PTR_TO_FUN, int, int);
PTR_TO_FUN select(char);

int add(int x, int y)
{
	return x+y;
}
int sub(int x, int y)
{
	return x-y;
}
int calc(PTR_TO_FUN fp, int x, int y)
// int calc(int (*fp)(int,int), int x, int y)
{
	return (*fp)(x,y);
}
PTR_TO_FUN select(char op)
// int (*select(char op))(int,int);
{
	switch(op)
	{
		case '+': return add;
		case '-': return sub;
	}
}

int main()
{
	int x,y;
	char op;
	int (*fp)(int,int);
	
	printf("Give me the calculation (x+y) or (x-y):\n");
	scanf("%d%c%d",&x,&op,&y);
	
	fp = select(op);
	printf("%d %c %d = %d\n", x, op, y, calc(fp,x,y));
	
	return 0;
}
