#include <stdio.h>

int main()
{	
	int n, i;

	printf("i = ");
	scanf("%d", &i);	
	
	while(i>0)
	{
		n = i %10;
		i /= 10;

		


	}

	printf("%d\n", i);	
	
	return 0;
}
