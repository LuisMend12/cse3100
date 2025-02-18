#include <stdio.h>

int main()
{
	int i, n, sum, j;
	sum = 0;
	printf("Enter n:\n");
	scanf("%d", &n);
	i = 1;
	while (i <= n)
	{
		sum += i;
		i += 1;

	}

	printf("Sum from 1 to %d = %d\n", n, sum);

	j = n*(n+1)/2;
	printf("Formula result: %d\n", j);




	int N = 1000000;
	printf("Among 1, 10, 100, 1000, 10000, 100000, 1000000\n");
	printf("The smallest number to break the code is %d\n", N);


	return 0;
}
