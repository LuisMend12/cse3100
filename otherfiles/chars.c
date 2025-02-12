#include <stdio.h>
int main()
{
	printf("\x7\n\n\07");
	printf("\tFirst!\tSecond!\tLast!\n");
	printf("\tFirst!\tSecond!\tLast!\b\b\b\b\b\bOops!\n");

	printf("\x7\n\n\07");
	printf("Can you see this?\r");
	printf("\tFirst!\tSecond!\tLast!\b\b\b\b\b\bOops!\n");


	float f = 32.2;
	int i = f;
	printf("%d", i);
	return 0;
}
