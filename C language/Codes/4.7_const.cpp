#include <stdio.h>

int main()
{
	// part 1: constant variable pointer, the variable only readable,
	// but we can redirect the pointer. (after re-direct, still only readable)
	int num = 520;
	const int cnum = 886;
	const int* pc = &cnum;
	
	printf("cnum: %d, &cnum: %p\n", cnum, &cnum);
	printf("*pc: %d, pc: %p\n\n", *pc, pc);
	
	pc = &num; // const int pointer can be change to another address!
	
	printf("num: %d, &num: %p\n", num, &num);
	printf("*pc: %d, pc: %p\n\n", *pc, pc);

	num = 1314; // num is not const, so it can be changed!
	
	printf("num: 520 -> 1314\n");
	printf("num: %d, &num: %p\n", num, &num);
	printf("*pc: %d, pc: %p\n\n", *pc, pc);
	
	// part 2: Constant pointer
	int num2 = 520;
	const int cnum2 = 886;
	int* const p = &num2; // const over p, the pointer can not be change!
	
	printf("*p = %d\n",*p);
	*p = 1024;
	printf("*p: 520 -> 2014, *p = %d\n", *p);
	
	//part 3: constant variable + constant pointer (top safety? or boring)
	const int cnum3 = 1234;
	const int* const cpc = &cnum3;
	
	// illigel to
	//*cpc++; //cnum3++;
	
	return 0;
}
