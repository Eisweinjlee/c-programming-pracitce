#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book
{
	char name[50];
	char author[50];
	struct Book *next;
};

void getInput(struct Book *book)
{
	printf("Input the name: ");
	scanf("%s", book->name);
	printf("Input the author: ");
	scanf("%s", book->author);
}

void addBook(struct Book **library)
{
	struct Book *book;
	static struct Book *tail; // static value saves the tail pointer
	
	book = (struct Book*) malloc(sizeof(struct Book));
	if(book == NULL)
	{
		exit(1);
	}
	
	getInput(book);
	if(*library != NULL)
	{
		// input to the tail
		tail->next = book;
		book->next = NULL;
	}
	else
	{
		*library = book;
		book->next = NULL;
	}
	tail = book; // a new tail
}

void printLib(struct Book *library)
{
	struct Book *book;
	int count = 1;
	
	book = library;
	
	printf("\n\nStart to print the library:\n\n");
	while(book != NULL)
	{
		printf("Book %d: ", count);
		printf("%s, ", book->name);
		printf("%s\n", book->author);
		book = book->next;
		count++;
	}
}

void releaseLib(struct Book *library)
{
	struct Book *temp;
	while(library != NULL)
	{
		temp = library;
		library = library->next;
		free(temp);
	}
}

struct Book *searchBook(struct Book *library, char *target)
{
	struct Book *book;
	
	book = library;
	while(book != NULL)
	{
		if((!strcmp(book->name, target)) || (!strcmp(book->author, target)))
		{
			break;
		}
		book = book->next;
	}
	return book;
}

void printBook(struct Book *book)
{
	printf("\nName: %s\n", book->name);
	printf("Author: %s\n", book->author);
}

int main()
{
	struct Book *library = NULL;
	struct Book *book;
	char ch;
	char str[50];
	
	while(1)
	{
		printf("New book input? (Y/N)");
		do
		{
			ch = getchar();
		} while(ch != 'Y' && ch != 'N');
		
		if(ch == 'Y')
		{
			addBook(&library);
		}
		else
		{
			break;
		}
	}
	
	printf("Print the library? [Y/N] ");
	do{
		ch = getchar();
	}while(ch != 'Y' && ch != 'N');
	if(ch == 'Y')
	{
		printLib(library);
	}
	
	printf("\nThe name or author you want to search: ");
	scanf("%s", str);
	
	book = searchBook(library, str);
	if(book == NULL)
	{
		printf("Sorry, there is no this book.\n");
	}
	else
	{
		printf("\nYour request is found:\n");
		do
		{
			printBook(book);
		} while( (book = searchBook(book->next, str)) != NULL);
	}
	
	releaseLib(library);
	
	return 0;
}
