#include<stdio.h>

char* getword(char c)
{
	switch(c)
	{
		case 'A': return "Apple";
		case 'B': return "Banana";
		case 'C': return "Cat";
		case 'D': return "Dog";
		default: return "Error input";
	}
}


int main()
{
	char input;
	printf("Give me a letter: ");
	scanf("%c", &input);
	
	printf("%s\n", getword(input));
	
	return 0;
}
