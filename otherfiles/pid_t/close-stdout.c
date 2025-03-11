#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv){
    int v1, v2;

    v1 = printf("Specify an argument to close stdout (1).\n");

    if (argc > 1){
        close(1);
        v1 = printf("stdout is close. argv[1]='%s'n", argv[1]);
    } else {
        v1 = printf("stdout remains open.\n");
    }

    v2 = fflush(stdout);

    fprintf(stderr, "printf() returned %d.\nfflush() returned %d\n", v1, v2);
    return 0;
}