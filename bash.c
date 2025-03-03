#include <stdio.h>
#include <unistd.h>

int main() {
    int test = fork();
    if (test == 0) {
        printf("a is child %d\n", test);
        printf("This is a child, PID: %d\n", getpid());
    }


    if (test>0) {
        printf("a is parent %d\n", test);
        printf("this is in parent, PID %d\n", getpid());
    }
}