#include <stdio.h>

int main()
{
	int num = 1024;
	int* pi = &num;
	
	char* ps = "Hello!";
	
	void* pv = NULL; // a void pointer given NULL
	printf("NULL pointer: %p\n\n", pv);
	
	pv = pi;
	printf("pi: %p, pv: %p\n",pi,pv);
	printf("*pv: %d\n\n",*(int*)pv);
	
	pv = ps;
	printf("ps: %p, pv: %p\n",ps,pv);
	printf("pv: %s\n",(char*)pv);
	
	return 0;
}
