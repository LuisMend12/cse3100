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

	flie = open("newfile.txt", O_RDWR | O_CREATE, 0750);

	if (file < 0)
	{
		printf("Error!\n");
		exit(1);
	}


	return(0);


}

