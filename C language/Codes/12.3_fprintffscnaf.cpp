#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	FILE *fp;
	struct tm *p;
	time_t t;
	
	time(&t);
	p = localtime(&t);
	
	
	// write
	if((fp = fopen("date.txt", "w")) == NULL)
	{
		printf("open failure!\n");
		exit(EXIT_FAILURE);
	}
	
	fprintf(fp, "%d-%d-%d", 1900+p->tm_year, 1+p->tm_mon, p->tm_mday);
	fclose(fp);
	
	// read
	int year, month, day;
	
	if((fp = fopen("date.txt", "r")) == NULL)
	{
		printf("open failure!\n");
		exit(EXIT_FAILURE);
	}	
	
	fscanf(fp, "%d-%d-%d", &year, &month, &day);
	printf("The time written in file is:\n%d-%d-%d\n",year,month,day);
	fclose(fp);
	
	return 0;
}
