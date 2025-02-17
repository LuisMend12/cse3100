#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;

	printf("n = ");
	scanf("%d", &n);

	int m = n;
	//TODO
	//add code below

	int sum = 0;
	
	// The conditions for this while loop are if n is not equal to one, because this means that n is a happy number if it equals to one, and that n shouldn't equal to 4, because it would mean that n is not a happy number given that if we get 4 that means that the sum of the digits from 4 will return back to 4.
	while (n != 1 && n != 4) 
	{
		// Resets the value sum for each iteration, this is to make sure that the sum of the digits is being added separetely and then
		sum = 0;
		// I used this while loop to find each digit of the number n and sum all of its digits
		while (n>0)
		{	
			
			int digit = n%10;
			sum += digit*digit;
			n/=10;
		}

		n = sum;
		printf("%d\n", sum);
	}

	
	if(n==1) printf("%d is a happy number.\n", m);
	else printf("%d is NOT a happy number.\n", m);
	return 0;
}
