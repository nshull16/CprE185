/* Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define TOL 0.05

/* Put your lab 4 functions prototypes here, as well as the prototype for lab 5 */
double mag(double ax, double ay, double az);
int close_to(double tolerance, double point, double value);
int close_toneg(double tolerance, double point, double value);


int main(void) {
	int t, b1, b2, b3, b4, b5, s;
	double ax, ay, az;
	double pointpos = 1;
	double pointneg = -1;
	int orientation = 0;


	while (TRUE) {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &s );	

/* CODE SECTION 0 */
		// printf("Echoing output: %d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d\n", t, ax, ay, az, b1, b2, b3, b4, b5, s);

/* 	CODE SECTION 1 */
		// printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay, az)); 
		if(close_to(TOL, pointpos, az) == 1 && orientation != 1) {
			printf("TOP\n");
			orientation = 1;
		}
		else if((close_toneg(-TOL, pointneg, az)) == 1 && orientation != 2) {
			printf("BOTTOM\n");
			orientation = 2;
		}
		else if((close_to(TOL, pointpos, ax))  == 1 && orientation != 3){
			printf("RIGHT\n");
			orientation = 3;
		}
		else if((close_toneg(-TOL, pointneg, ax)) == 1 && orientation != 4){
			printf("LEFT\n");
			orientation = 4;
		}
		else if((close_to(TOL, pointpos, ay)) == 1 && orientation != 5){
			printf("FRONT\n");
			orientation = 5;
		}
		else if((close_toneg(-TOL, pointneg, ay)) == 1 && orientation != 6){
			printf("BACK\n");
			orientation = 6;
		}
		if(b2 == TRUE){
			break;
		}
	}
    return 0;
}


/* Put your lab 4 functions here, as well as your new function close_to */
double mag(double ax, double ay, double az){
	return sqrt((ax*ax)+(ay*ay)+(az*az));
}
int close_to(double tolerance, double point, double value){
	if ((point-value) <= tolerance){
		return TRUE;
	}
}
int close_toneg(double tolerance, double point, double value){
	if ((point-value >= tolerance)){
		return TRUE;
	}
}