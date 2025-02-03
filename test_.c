#include <stdio.h>
#include <string.h>


int main() 
{
	printf("Hello World!\n");

	fwrite(STDOUT_FILENO, "Hello World!\n", sizeof("Hello World!\n"));

	return 0;
}
