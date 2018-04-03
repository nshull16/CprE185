#include <stdio.h>

int main() {
	
	int ansA, ansB, ansE, ansF, ansJ;
	double ansC, ansD, ansG, ansH, ansI, ansK;
	double areaCircle, feetMeters, fahCen;
	double pi = 3.14;
	
	ansA = (6427 + 1725);
	printf("6427 + 1725 = %d\n", ansA);
	
	ansB = (6971 * 3925) - 95;
	printf("6971 * 3925 = %d\n", ansB);
	
	ansC = (79 + 12 / 5);
	printf("79 + 12 / 5 = %0.2lf\n", ansC);
	
	ansD = (3640.0/107.9);
	printf("3640.0/107.9 = %0.2lf\n", ansD);
	
	ansE = ((22/3)*3);
	printf("(22/3)*3 = %d\n", ansE);
	
	ansF = (22/(3*3));
	printf("22/(3*3) = %d\n", ansF);
	
	ansG = (22/(3*3));
	printf("22/(3*3) = %0.2lf\n", ansG);
	
	ansH = (22/3*3);
	printf("22/3*3 = %0.2lf\n", ansH);
	
	ansI = ((22.0/3)*3.0);
	printf("(22.0/3)*3.0 = %0.2lf\n", ansI);
	
	ansJ = (22.0/(3*3.0));
	printf("22.0/(3*3.0) = %d\n", ansJ);
	
	ansK = (22.0/3.0*3.0);
	printf("22.0/3.0*3.0 = %0.2lf\n", ansK);
	
	areaCircle = (23.567/ (2 * pi)) * (23.567 / (2 * pi)) * pi;
	printf("The area of a cirle with a circumference of 23.567 = %0.2lf\n", areaCircle);
	
	feetMeters = (14 * .3048);
	printf("14 feet = %0.2lf meters\n", feetMeters);
	
	fahCen = ((76-32) / 1.8);
	printf("76 degrees Fahrenheit = %0.2lf degrees Centigrade\n", fahCen);
	
}