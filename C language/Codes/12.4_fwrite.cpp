#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Date
{
	int year;
	int month;
	int day;
};

struct Book
{
	char name[50];
	char author[50];
	struct Date date;
};

int main(void)
{
	FILE *fp;
	struct Book *book_read, *book_write;
	
	// preparation
	book_read = (struct Book*) malloc(sizeof(struct Book));
	book_write = (struct Book*) malloc(sizeof(struct Book));
	if(book_read == NULL || book_write == NULL)
	{
		printf("memory allocated failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(book_write->name, "<the book title>");
	strcpy(book_write->author, "someone wrote the book");
	book_write->date.year = 2020;
	book_write->date.month = 04;
	book_write->date.day = 01;
	
	// write
	if((fp = fopen("test.txt", "w"))==NULL)
	{
		printf("open failed 1\n");
		exit(EXIT_FAILURE);
	}
	fwrite(book_write, sizeof(struct Book), 1, fp);
	fclose(fp);
	
	// read
	if((fp = fopen("test.txt", "r"))==NULL)
	{
		printf("open failed 1\n");
		exit(EXIT_FAILURE);
	}
	fread(book_read, sizeof(struct Book),1,fp);
	printf("Title: %s\n", book_read->name);
	printf("Author: %s\n", book_read->author);
	printf("Date: %d-%d-%d\n", book_read->date.year, book_read->date.month, book_read->date.day);
	fclose(fp);
	
	// clean
	free(book_read);
	free(book_write);
	
	return 0;
}
