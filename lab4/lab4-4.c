/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */

int main(void) {
	int a, b, c, d, e, f; 	
	

	while (TRUE) {
		scanf("%d, %d, %d, %d, %d, %d", &a, &b, &c, &d, &e, &f);	
		
		
		printf("Number of buttons pressed: %d\r\n", (a + b + c + d + e) );
		fflush(stdout);
	}

	return 0;
}
