/* Lab 6 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define TRUE 1
#define FALSE 0

/* Prototypes */
double mag(double ax, double ay, double az);
int close_to(double tolerance, double point, double value);
double velocityChange (double currentTime, double secondTime, double magnitude);
double airResistance (double originalPosition, double velocity, double secondTime, double currentTime);
int percentChange(double originalPosition, double finalPosition);


int main (void) {
	int t;
	double ax, ay, az;
	double timeFall, currentTime, lastPrint, lastEx, fallTime, airPosition, secondTime;
	bool exe = false;
	bool drop = false;
	bool exe3 = false;
	
	double velocity = 0;
	double originalPosition = 0;
	scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
	secondTime = t / 1000.0;
	
	while(TRUE) {
		scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
		currentTime = t / 1000.0;
		velocity += velocityChange (currentTime, secondTime, mag(ax, ay, az));
		originalPosition = airResistance(originalPosition, velocity, secondTime, currentTime);
		secondTime = currentTime;
		
		
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
				break;
			}
			if(!drop && currentTime - lastPrint >= (.1)) {
				printf(".");
				lastPrint = currentTime;
			}
		}
		fflush(stdout);

	}
	printf("\nOuch! I fell %lf meters in %lf seconds\n", (4.9*fallTime*fallTime), fallTime);
	printf("Compensating for air resistance, the fall was %lf meters.\n", originalPosition);
	printf("This is %d%% less than computed before", percentChange((4.9*fallTime*fallTime), originalPosition));
	
	return 0;
}

	

/* Functions */



double velocityChange (double currentTime, double secondTime, double magnitude){
	return (9.8 * (1-magnitude)) * (currentTime - secondTime);
}
double airResistance (double originalPosition, double velocity, double secondTime, double currentTime) {
	return (originalPosition + velocity * (currentTime - secondTime));
}
int percentChange(double originalPosition, double airPosition) {
	return (1 - (airPosition / originalPosition)) * 100;
}

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

