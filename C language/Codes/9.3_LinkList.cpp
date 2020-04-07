#include<stdio.h>
#include<stdlib.h>

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
	
	book = (struct Book*) malloc(sizeof(struct Book));
	if(book == NULL)
	{
		exit(1);
	}
	
	getInput(book);
	if(*library != NULL)
	{
		book->next = *library;
		*library = book;
	}
	else
	{
		*library = book;
		book->next = NULL;
	}
	
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

int main()
{
	struct Book *library = NULL;
	char ch;
	
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
	printLib(library);
	releaseLib(library);
	
	return 0;
}
