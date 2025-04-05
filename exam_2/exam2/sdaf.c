#include <stdio.h>
#include <unistd.h>
#include <unistd.h>

int main() {
    char * args[] = {"ls", NULL};

    execv(args[0], args);

    printf("THis si bad!\n");

    return 0;
}