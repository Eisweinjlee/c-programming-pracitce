#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "I am really happy today!";
	char str2[] = "New string copied!";
	char str3[100];
	
	printf ("%s\n", str1);
	
	// the size
	printf("sizeof(): %d\n", sizeof(str1));
	printf("strlen(): %u\n", strlen(str1)); // strlen returns unsigned int!! be better using %u
	printf("\n");
	
	// copy the string
	strcpy(str1,str2); // str1 should be large enough to hold str2!!
	strcpy(str3, "Copy successfully!");
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("str3: %s\n", str3);
	printf("\n");

	// combine the string
	char str4[] = "The str4!";
	char str5[] = "And the str5!";
	strcat(str4," ");
	strcat(str4, str5);
	printf("str4: %s\n", str4);
	printf("str5: %s\n", str5);
	printf("\n");
	
	// compare the string
	printf("If different, the strcmp: %d\n", strcmp(str4,str5));
	printf("If being same, the strcmp: %d\n", strcmp(str4,str4));
	
	return 0;
}
