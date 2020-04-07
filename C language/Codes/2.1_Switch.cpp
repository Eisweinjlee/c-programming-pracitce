#include <stdio.h>

int main()
{
	char level;
	
	printf("input a level (A-D):" );
	scanf("%c", &level);
	getchar();
	
	switch(level)
	{
		case 'A' : printf("you have got 90-100."); break;
		case 'B' : printf("you have got 80-89."); break;
		case 'C' : printf("you have got 70-79."); break;
		case 'D' : printf("you have passed."); break;
		default: printf("Error input");
	}
	
	return 0;
}
