#include<stdio.h>
#include<string.h>

int main(void)
{
	char buff[1024];
	
	memset(buff, '\0', sizeof(buff)); // fill \0 to all buff
	
	setvbuf(stdout, buff, _IOFBF, 1024);
	
	fprintf(stdout, "Welcome to the C programming world!\n");
	
	fflush(stdout);
	
	fprintf(stdout, "How to see this line?\n");
	
	getchar();
	
	return 0;
}
