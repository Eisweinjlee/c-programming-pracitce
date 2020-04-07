#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	FILE *fp;
	char ch;
	
	if( (fp = fopen("hello.txt", "w"))==NULL)
	{
		printf("read file error.\n");
		exit(EXIT_FAILURE);
	}
	
	printf("%ld\n",ftell(fp));
	fputc('W',fp);
	printf("%ld\n",ftell(fp));
	fputs("orld!\n", fp);
	printf("%ld\n",ftell(fp));
	
	rewind(fp);
	fputs("Hello ", fp);
	
	fclose(fp); 
	
	if( (fp = fopen("hello.txt", "r"))==NULL)
	{
		printf("read file error.\n");
		exit(EXIT_FAILURE);
	}
	while((ch = getc(fp)) != EOF)
	{
		putchar(ch);
	}
	fclose(fp);
	
	return 0;
}
