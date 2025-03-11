#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;

	printf("n = ");
	scanf("%d", &n);
	// powerof16 is used instead of a power function which is initialized at 1 because the first power of 16 is 1. After each iteration, the powerof16 is multiply by 16 each time
	double powerof16 = 1.0;

	double pi = 0.0;
	//TODO
	//add code below 

	for (i=0; i<=n; i++)
	{
		// This is the series provided in the HW pdf
		double approx = ((4.0 / (8.0 * i + 1.0)) - (2.0 / (8.0 * i + 4.0)) - (1.0 / (8.0 * i + 5.0)) - (1.0 / (8.0 * i + 6.0))) / powerof16;
		// addts the sum of the series into the variable pi
		pi += approx;

		// Instead of using pow(16, i), I used powerof16. This is because by each iteration, after computing the term, this multiplies powerOf16 by 16 to get the next power.
		powerof16 *= 16.0;
	}



	printf("PI = %.10f\n", pi);
	return 0;
}