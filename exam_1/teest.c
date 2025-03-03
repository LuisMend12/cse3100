#include <assert.h>
#include <stdio.h>
//TODO

void FirstDigitCount(unsigned *a, unsigned n, unsigned freq[10])
{
	int left = 0;
    int right = n - 1;

    for(int i = n - 1; i >= 0; i--) {
		int first_d = firstDigit(a[i]);
		if (freq[first_d]) freq[first_d]++;
		else continue;
	}

}

int main()
{


    int first_d;

    int  k = 9000000;

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

    printf("%d\n", first_d);

    return 0;

}

