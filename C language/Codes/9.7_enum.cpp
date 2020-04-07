#include<stdio.h>
int main(void)
{
	enum WEEK {mon = 1 , tue, wed, thu, fri, sat, sun};
	// from 0, 1, 2, 3.... by default
	enum WEEK day;
	
	day = mon;
	
	switch(day)
	{
		case mon:
		case tue:
		case wed:
		case thu:
		case fri:
			printf("Work work!\n");
			break;
		case sat:
		case sun:
			printf("Chill!!\n");
			break;	
		default:
			printf("Error\n");
	}
	
	printf("mon = %d\n", mon);
	printf("tue = %d\n", tue);
	printf("sun = %d\n", sun);
	
	return 0;
}
