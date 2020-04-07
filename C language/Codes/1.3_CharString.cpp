#include <stdio.h>

int main()
{
	char a = 'C';
	printf("%c = %d (ASCII). \n", a,a);
	
	int b = 68;
	printf("%d (ASCII) -> %c. \n", b,b);
	
	char name[8] = {'L','i',' ','Y','a','n','g','\0'};
	printf("%s\n",name);
	
	char date[] = {"Mar 18th, 2020"};
	printf("Today is %s\n", date);
	
	return 0;
}
