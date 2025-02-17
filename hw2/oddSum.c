#include <stdio.h>
#include <stdlib.h>

int oddSumHelp(int count, int bound, int value)
{
    if ((count == 0) && (value == 0)) {
        return 1;
    }
    if ((count <= 0) || (value <= 0)) {
        return 0;
    }

    for (int i = bound; i > 0; i -= 2) {  // Fixed iteration to use 'i'
        if (oddSumHelp(count - 1, i - 2, value - i)) {
            printf("%d ", i);
            return 1;
        }
    }
    return 0;
}

// Do not change the code below
int oddSum(int count, int bound, int value)
{
    if (value <= 0 || count <= 0 || bound <= 0) return;

    if (bound % 2 == 0) bound -= 1;

    if (!oddSumHelp(count, bound, value))
        printf("No solutions.\n");
    else
        printf("\n");
	//fill in your code below
    int number_arr[12] = {1, 3, 7, 13, 15, 17, 19, 21, 23, 25, 27, 29};


    //for (int i = 0; i < count; ++i)
    //{   
    //} 




}

//Do not change the code below
void oddSum(int count, int bound, int value)
{
    	if(value <= 0 || count <= 0 || bound <= 0) return;
    
    	if(bound % 2 == 0) bound -= 1;

    	if(!oddSumHelp(count, bound, value)) printf("No solutions.\n");
	else printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc != 4) return -1;

    int count = atoi(argv[1]);
    int bound = atoi(argv[2]);
    int value = atoi(argv[3]);

    // Uncomment this line to use the command-line arguments:
    oddSum(count, bound, value);

    // Comment out these test cases if not needed:
    // oddSum(12, 30, 200);
    // oddSum(10, 20, 100);
    // oddSum(20, 20, 200);

    return 0;
    
	if (argc != 4) return -1;

	int count = atoi(argv[1]);
	int bound = atoi(argv[2]);
	int value = atoi(argv[3]);

	//oddSum(12,30,200);
	//oddSum(10,20,100);
	//oddSum(20,20,200);
	oddSum(count, bound, value);
	return 0;
}
