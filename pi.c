#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


/* Name: Maram Ahmer
   Student Number: 250963151
   This program calculates an estimation of pi
   compile in c99 and use math library
*/
double estimate_pi(long long N){
	float x, y;
	double ratio, my_pi;
        int inside_circle;
	
	// do some error checking on the input N, and initialize random numbers between 1-0
	if ( N < 0 ){
		printf("Error: Invalid number\n");
		exit(EXIT_FAILURE);
	}
	x = 0.0;
	y = 0.0;
        for (int i=0; i < N; i++){
		// generate random numbers for x and y, and use the valid pairs to calculate an approximation for pi
                x = ((double) rand() / (RAND_MAX)) ;
		y = ((double) rand() / (RAND_MAX)) ;
		//printf("%f\n%f\n", x, y);

		float x_power = x*x;
		float y_power = y*y;
        	if( x_power + y_power <= 1){
			inside_circle++;
		}	
	}
	ratio = (double)inside_circle / (double)N;
	my_pi = 4 * ratio;
	
	inside_circle = 0;
	return my_pi;
}

int main(void){
	int N;
	float found_pi, power_pi, mean, power_mean, standard_deviation;
	srand(time(NULL));
	printf("Enter a number for N: ");
	scanf("%d", &N);
	
	// loop and find the value of pi 10 times
	for(int i=0; i<10; i++){
		printf("Pi: %.10f\n", estimate_pi(N)); 
		found_pi+= estimate_pi(N);
		power_pi += (estimate_pi(N) * estimate_pi(N));	
	}

	//calculate for the mean and standard deviation
	mean = (double)found_pi / (double)N;
	power_mean = mean * mean;
	standard_deviation = sqrt(((double)power_pi / (double)N) - power_mean);
	
	printf("Mean: %.10f\nStandard Deviation: %.10f\n", mean, standard_deviation);
	return 0;

}
