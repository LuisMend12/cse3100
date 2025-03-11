#include <stdio.h>

int main()
{	

	double x, average, total = 0.0;
	int count = 0.0;

	while (scanf("%lf", &x) == 1)
	{
		total += x;
		count++;
		average = total/count;
		printf("Total=%f Average=%f\n", total, average);
	};

	

	return 0;
}
