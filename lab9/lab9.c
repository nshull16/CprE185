// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
//Updated for Esplora 2013 TeamRursch185


// Headers
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <stdlib.h>

// Mathematical constants
#define PI 3.14159

// Screen geometry
// Use ROWS and COLUMNS for the screen height and width (set by system)
// MAXIMUMS
#define COLUMNS 100
#define ROWS 80

// Character definitions taken from the ASCII table
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

// Number of samples taken to form an average for the accelerometer data
// Feel free to tweak this.  You may actually want to use the moving averages
// code you created last week 
#define NUM_SAMPLES 10  


// 2D character array which the maze is mapped into
char MAZE[COLUMNS][ROWS];


// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty);

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void);

// PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use);

// PRE: -1.0 < x_mag < 1.0
// POST: Returns tilt magnitude scaled to -1.0 -> 1.0
// You may want to reuse the roll function written in previous labs.  
double calc_roll(double x_mag);

int close_to(double tolerance, double point, double value);
double avg(double buffer[], int num_items);
void updatebuffer(double buffer[], int length, double new_item);

// Main - Run with './explore.exe -t -a -b' piped into STDIN
void main(int argc, char* argv[])
{
	double a_x, a_y, a_z;
	double currentTime, average;
	double x[1000];
	double lastMove = 0.0;
	int difficulty, i, j;
	int t, b_Down, b_Up, b_Left, b_Right, b_Joy, slider;
	int r = 0;
	int c = 50;
	
	sscanf(argv[1], "%d", &difficulty);

	initscr(); 	// setup screen    
	refresh();

	
	
	generate_maze(difficulty); // Generate and draw the maze, with initial avatar
	draw_maze();
	for (i=0; i < NUM_SAMPLES; ++i) { // Read accelerometer data to get ready for using moving averages.    
		scanf(" %d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &a_x, &a_y, &a_z, &b_Down, &b_Up, &b_Left, &b_Right, &b_Joy, &slider);
		x[i] = a_x;
	}
	
	do // Event loop
	{

		scanf(" %d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &a_x, &a_y, &a_z, &b_Down, &b_Up, &b_Left, &b_Right, &b_Joy, &slider);// Read data, update average
		currentTime = t/1000.0;
		if (currentTime - lastMove >= .4) {// Is it time to move?  if so, then move avatar
			average = avg(x, NUM_SAMPLES);
			if(r<81) {
				draw_character(c, r-1, EMPTY_SPACE);
				
				if(MAZE[c-1][r] != WALL && ((average) > .4)) {
					draw_character(c, r, EMPTY_SPACE);
					--c;
					draw_character(c, r, AVATAR);
				}
				else if(MAZE[c+1][r] != WALL && (calc_roll(average) == -1)) {
					draw_character(c, r, EMPTY_SPACE);
					++c;
					draw_character(c, r, AVATAR);
				}
				else if(MAZE[c][r] != WALL && (calc_roll(average) == 0)) {
					draw_character(c, r-1, EMPTY_SPACE);
					draw_character(c, r, AVATAR);
				}
				else if(MAZE[c+1][r] == WALL && MAZE[c-1][r] == WALL && MAZE[c][r+1] == WALL) {
					break;
				}
				if(MAZE[c][r+1] != WALL) {
					++r;
				}
			}
			lastMove = currentTime;
	}
	updatebuffer(x, NUM_SAMPLES, a_x);	
	}
	while(r != 81); // Change this to end game at right time 
	endwin();
	
	if(r != 81) {
		printf("YOU LOSE.\n");
	}
	if (r == 81) {
	printf("YOU WIN!\n"); // Print the win message
}
}





// PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//YOU DO NOT NEED TO CHANGE THIS FUNCTION.
void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}

void generate_maze(int difficulty) {
	int i, j;
	for (i=0; i < COLUMNS; ++i){
		for (j=0; j < ROWS; ++j){
			if(difficulty > rand() % 100) {
				MAZE[i][j] = WALL;
			}
			else {
				MAZE[i][j] = EMPTY_SPACE;
			}
		}
	}
}

void draw_maze(void) {
	int i, j;
	for (i=0; i < COLUMNS; ++i){
		for (j=0; j < ROWS; ++j){
			draw_character(i, j, MAZE[i][j]);
		}
	}
}

double calc_roll(double x_mag) {
	
	if (x_mag > .3){
		x_mag = 1;
	}	
	if (x_mag < -.3){
		x_mag = -1;
	}
	else if(close_to(.3, 0, x_mag) == 1) {
		x_mag = 0;
	}
	return x_mag;
}

int close_to(double tolerance, double point, double value){
	if ((tolerance >= (point - value))){
		return 1;
	}
	else {
		return 0;
	}
}

double avg(double buffer[], int num_items){
	int i = 0;
	double sum = 0.0;
	double average = 0.0;
	for (i=0; i < num_items; ++i){
		sum = buffer[i] + sum;
	}
	average = ((sum) / num_items);
	return average;
}

void updatebuffer(double buffer[], int length, double new_item){
	int i = 0;
	for (i=0; i < (length -1) ; ++i) {
		buffer[i] = buffer[i+1];
	}
	buffer[length-1] = new_item;
}
