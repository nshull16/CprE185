#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);



int main(int argc, char* argv[]) {
	
	int time, b1, b2, b3, b4, slider, joystick;
	int i = 0;
	double ax, ay, az, x_avg, y_avg, z_avg;
	double x_min = 10;
	double x_max = -10;
	double y_min = 10;
	double y_max = -10;
	double z_min = 10;
	double z_max = -10;

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}

	/* Put your code here */
	
	for (i=0; i<lengthofavg; ++i){
		scanf(" %d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &time, &ax, &ay, &az, &b1, &b2, &b3, &b4, &slider, &joystick);
		x[i] = ax;
		y[i] = ay;
		z[i] = az;
	}
	
	while (b3 != 1){
		
		scanf(" %d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &time, &ax, &ay, &az, &b1, &b2, &b3, &b4, &slider, &joystick);
		
		x_avg = avg(x, lengthofavg);
		y_avg = avg(y, lengthofavg);
		z_avg = avg(z, lengthofavg);
		
		updatebuffer(x, lengthofavg, ax);
		updatebuffer(y, lengthofavg, ay);
		updatebuffer(z, lengthofavg, az);
	
		maxmin(x, lengthofavg, &x_max, &x_min);
		maxmin(y, lengthofavg, &y_max, &y_min);
		maxmin(z, lengthofavg, &z_max, &z_min);
		
		printf(" %d, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n", time, x_avg, y_avg, z_avg, x_min, x_max, y_min, y_max, z_min, z_max);
		
		fflush(stdout);
	}
}

double avg(double buffer[], int num_items){
	int i = 0;
	double sum = 0.0;
	double avg = 0.0;
	for (i=0; i < num_items; ++i){
		sum = buffer[i] + sum;
	}
	avg = ((sum) / num_items);
	return avg;
}

void maxmin(double array[], int num_items, double* max, double* min){
	int i = 0;
	for (i=0; i < num_items; ++i) {
		if (array[i] > *max) {
			*max = array[i];
		}
		else if (array[i] < *min) {
			*min = array[i];
		}
	}
}

void updatebuffer(double buffer[], int length, double new_item){
	int i = 0;
	for (i=0; i < (length -1) ; ++i) {
		buffer[i] = buffer[i+1];
	}
	buffer[length-1] = new_item;
}




