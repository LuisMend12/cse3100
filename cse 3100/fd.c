#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>


int main(){


	int file;

	// 0  User Group Other

	// R: 4  	W : 2 	  X : 1

	file = open("hello.txt", O_RDWR | O_CREAT, 0000);

	if (file < 0)
	{
		printf("Error!\n");
		exit(1);
	}

    int x;
    x = close(file);

    if (x < 0)
    {
		printf("Error!\n");
		exit(1);
	}


    int y;

    y = remove("hello.txt");

    if (y < 0) {
        printf("Error!\n");
        exit(1);
    }

	return(0);


}

