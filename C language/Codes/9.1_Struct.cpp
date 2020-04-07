#include<stdio.h>

struct Date
{
	int year;
	int month;
	int day;
} ;

struct Book
{
	char title[50];
	char author[50];
	float price;
	struct Date date;
} book;

int main()
{
	printf("Please input book title: ");
	scanf("%s", book.title);
	printf("Please input author's name: ");
	scanf("%s", book.author);
	printf("Please input the price: ");
	scanf("%f", &book.price);
	
	printf("Please input the date[YY/MM/DD]: ");
	scanf("%d/%d/%d", &book.date.year, &book.date.month, &book.date.day);
	
	printf("\n========= Finished =========\n\n");
	
	printf("%s, %s, %f, %d/%d/%d\n\n", book.title, book.author, book.price, book.date.year, book.date.month, book.date.day);
	
	// Pointer
	struct Book *pt;
	pt = &book;
	
	printf("(*pt).title = %s, pt->title = %s\n", (*pt).title, pt->title);
	
	return 0;
}
