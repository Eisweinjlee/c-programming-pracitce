#include<stdio.h>
#include<stdlib.h>

#define MAX 1024

int main(void)
{
	FILE *fp;
	char buffer[MAX];
	
	if( (fp = fopen("lines.txt" , "w")) == NULL)
	{
		printf("failed open.\n");
		exit(EXIT_FAILURE);
	}
	fputs("Line 1: Hello world!\n", fp);
	fputs("Line 2: I love C!\n", fp);
	fputs("Line 3: Today is a nice day!\n", fp);
	fclose(fp);
	
	if ((fp = fopen("lines.txt", "r")) == NULL)
	{
		printf("failed open.\n");
		exit(EXIT_FAILURE);
	}
	
	while(!feof(fp)) // feof = 1 if reading file reaches the end
	{
		if(fgets(buffer, MAX, fp) != NULL) 
		// reading file get NULL but eof = 0, buffer will keeps unchanged, the last line would be printed again! 
		{
			printf("%s", buffer);
		}
	}
	fclose(fp);
	
	return 0;
}
