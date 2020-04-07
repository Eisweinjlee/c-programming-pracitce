#include <stdio.h>

int main()
{
	// getchar() to get the string!!
	int count = 0;
	printf("Please input anything and end with ENTER.\n");
	
	char str[5000];
	
	while((str[count] = getchar()) != '\n')
	{
		count++;
	}
	
	str[count] = '\0'; // very very important for %s output!!
	
	printf("You have input %d numbers of char (included spaces)!\n", count);
	printf("What you input is:\n%s", str);
	
	/* while using scanf():
	for(i=0;i<num;i++)
	{
		scanf("%c", &str[i]);
	}
	getchar();
	str[i] = '\0';
	*/
	
	return 0;
}
