// lab7.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of explore data, and returns
//  True when left button is pressed
//  False Otherwise
//POST: it modifies its arguments to return values read from the input line.
int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT);

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the esplora in radians
// if x_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the esplora in radians
// if y_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);


// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number);

int main()
{
	double x, y, z;			// magnitude values of x, y, and z accelerations
	int b_Up, b_Down, b_Left, b_Right, t, slider, joystick;	// variables to hold the button statuses
	double roll_rad, pitch_rad;		// value of the roll measured in radians
	int scaled_value; 	// value of the roll adjusted to fit screen display
	bool pressUp = false;
	bool pressDown = false;
	//insert any beginning needed code here

	do
	{
		read_acc( &x, &y, &z, &t, &b_Up, &b_Down, &b_Left, &b_Right); // Get line of input
		
		
		if (b_Up == 1) { // check for button input
			pressUp = true;
			pressDown = false;
		}
		
		if (b_Down == 1) {
			pressDown = true;
			pressUp = false;
		}
		
		if (pressUp == true){
			roll_rad = roll(x);// calculate roll and pitch
			scaled_value = scaleRadsForScreen (roll_rad);// Scale your output value
			graph_line(scaled_value);// Output your graph line
		}
		
		if (pressDown == true) {
			pitch_rad = pitch(y);
			scaled_value = scaleRadsForScreen (pitch_rad);
			graph_line(scaled_value);
		}

		fflush(stdout);
	} 
	while (b_Left != 1); // Stops when left button is pressed
	return 0;
}
int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT) {
	int joystick, slider;
	return scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", time, a_x, a_y, a_z, Button_UP, Button_DOWN, Button_LEFT, Button_RIGHT, &slider, &joystick);
		if (*Button_LEFT == 1) {
			return 1;
		}
		else {
			return 0;
		}
}

double roll(double x_mag) {
	double xx = 0;
	if (x_mag > 1){
		x_mag = 1;
	}	
	if (x_mag < -1){
		x_mag = -1;
	}
	xx = asin(x_mag);
	return xx;
}

double pitch (double y_mag) {
	double yy = 0;
	if (y_mag > 1) {
		y_mag = 1;
	}
	if (y_mag < -1) {
		y_mag = -1;
	}
	yy = asin(y_mag);
	return yy;
}

int scaleRadsForScreen (double rad) {
	return (rad / (PI/2)) * 39;
}

void print_chars (int num, char use) {
	for (int i=0; i < fabs(num); ++i){
		printf("%c", use);
	}
}

void graph_line(int number) {
	if (number < 0) {
		for (int i =0; i < (40 + number); ++i) {
			printf(" ");
		}
		print_chars(number, 'l');
	}
	if (number > 0) {
		for (int i=0; i < 40; ++i) {
			printf(" ");
		}
		print_chars(number, 'r');
	}
	if (number == 0){
		for (int i = 0; i <  40; ++i) {
			printf(" ");
		}
		printf("0");
	}
	printf("\n");	
}