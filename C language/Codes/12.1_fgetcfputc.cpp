#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	FILE *fp1;
	FILE *fp2;
	int ch;
	
	if((fp1 = fopen("hello.txt", "r")) == NULL)
	{
		printf("Read file failed!\n");
		exit(EXIT_FAILURE); // in stdlib.h
	}
	
	if((fp2 = fopen("hello2.txt", "w")) == NULL)
	{
		printf("Read file failed!\n");
		exit(EXIT_FAILURE); // in stdlib.h
	}
	
	while((ch = getc(fp1)) != EOF)
	{
		putchar(ch);
		fputc(ch, fp2); // write to the hello2.txt
	}
	
	fclose(fp1); 
	fclose(fp2);// very important!
	
	return 0;
}
