// CprE 185: Lab 3
// Problem 1: Mysterious Output

#include <stdio.h>

int main()
{
		int integerResult;
		double decimalResult;
		
		integerResult = 77 / 5;
		printf("The value of 77/5 is %d\n", integerResult);
		
		integerResult = 2 + 3;
		printf("The value of 2+3 is %d\n", integerResult);
		
		decimalResult = 1.0 / 22.0;
		printf("The value of 1.0/22.0 is %lf\n", decimalResult);
		
		return 0;
}
