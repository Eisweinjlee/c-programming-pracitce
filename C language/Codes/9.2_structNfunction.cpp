#include<stdio.h>

struct Date
{
	int year;
	int month;
	int day;
};

struct Book
{
	char title[50];
	char author[50];
	float price;
	struct Date date;
};

struct Book getInput(struct Book book)
{
	printf("Please input book title: ");
	scanf("%s", book.title);
	printf("Please input author's name: ");
	scanf("%s", book.author);
	printf("Please input the price: ");
	scanf("%f", &book.price);
	
	printf("Please input the date[YY/MM/DD]: ");
	scanf("%d/%d/%d", &book.date.year, &book.date.month, &book.date.day);

	return book;
}

void printBook(struct Book book)
{
	printf("%s, %s, %f, %d/%d/%d\n\n", book.title, book.author, book.price, book.date.year, book.date.month, book.date.day);
}


int main()
{
	struct Book *b1, *b2;
	
	printf("Now please tell me about the first book......\n\n");
	b1 = getInput(b1);
	putchar('\n');
	printf("Now please tell me about the second book......\n\n");
	b2 = getInput(b2);
	
	printf("\n\n All finished!! The info is below\n");
	
	printBook(b1);
	printBook(b2);
	
	return 0;
}
