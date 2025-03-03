#include <assert.h>
#include <stdio.h>

//TODO
unsigned firstDigit(unsigned k)
{

	int first_d;

	if (k == 0)
	{
		first_d = 0;

	} else {
		while (k / 10)
		{
			int remainder = k % 10;
			first_d = k /= 10;
		}
	}

	return first_d;
}

//TODO
void FirstDigitCount(unsigned *a, unsigned n, unsigned freq[10])
{

    int right = n - 1;

    for(int i = right; i >= 0; i--) {
		int first_d = firstDigit(a[i]);
		freq[first_d]++;
	}
}