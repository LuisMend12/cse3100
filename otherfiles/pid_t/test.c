#include <stdio.h>
#include <sys/types.h>

int main(void) {
    pid_t var;

    var = -200;

    printf("size of int: %d\n", sizeof(int));
    printf("size if pid_t: %d\n", sizeof(pid_t));
    printf("value of var: %d\n", var);

    return 0;
}