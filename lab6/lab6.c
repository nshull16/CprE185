/* Lab 6 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define TRUE 1
#define FALSE 0

/* Prototypes */
double mag(double ax, double ay, double az);
int close_to(double tolerance, double point, double value);


int main (void) {
	int t;
	double ax, ay, az;
	double timeFall, currentTime, lastPrint, lastEx, fallTime;
	bool exe = false;
	bool drop = false;
	bool exe3 = false;
	
	while(TRUE) {
		scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
		currentTime = t / 1000.0;
		
		if(!exe) {
			printf("Ok, I'm now receiving data.\n");
			printf("I'm waiting");
			exe = true;
		}
		
		if(close_to(.5, 1, mag(ax, ay, az)) == FALSE) {
			if(!exe3) {
				printf("\nHelp me! I'm falling");
				timeFall = t/1000.0;
				exe3 = true;
				drop = true;
			}
			if(currentTime - lastEx >= .1) {
				printf("!");
				lastEx = currentTime;
			}
		}
		if(close_to(.5, 1, mag(ax, ay, az)) == TRUE) {
			if(drop) {
				fallTime = currentTime - timeFall;
				printf("\nOuch! I fell %lf meters in %lf seconds", (4.9*fallTime*fallTime), fallTime);
				break;
			}
			if(!drop && currentTime - lastPrint >= .1) {
				printf(".");
				lastPrint = currentTime;
			}
		}
	fflush(stdout);
	}
	return 0;
}

	

/* Functions */
double mag(double ax, double ay, double az){
	return sqrt((ax*ax)+(ay*ay)+(az*az));
}
int close_to(double tolerance, double point, double value){
	if ((tolerance >= (point - value))){
		return true;
	}
	else {
		return false;
	}
}

