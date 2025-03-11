#include <stdio.h>

int main() 
{

	int i = 0, sum = 0;
	do {
		sum += i++;
		printf("%d", i);
	} while (i < 100);

	return 0;
}
