#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main()
{
	FILE* fp;
	char ch;
	if((fp = fopen("score.txt", "rb")) == NULL)
	{
		fputs("failed to open!", stderr);
		exit(EXIT_FAILURE);
	}
	
	while(1)
	{
		ch = fgetc(fp);
		if(feof(fp))
		{
			break;
		}
		putchar(ch);
	}
	
	fputc('c',fp); // we cannot write in read mode
	if(ferror(fp)) //deal with error
	{
		fputs("ERROR!\n", stderr);
		//printf("Failed, because: %d\n", errno);
		perror("The error is because");
		//fprintf(stderr,"Error reason: %s, please check!\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	return 0;
}
