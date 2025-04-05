#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include <string.h>


#define MAX 1024
int main(int argc, char *argv[]) {


    int pd[2];
    assert(pipe(pd) != -1);

    pid_t pid = fork();


    if (pid == 0) {
        close(pd[1]);
        dup2(pd[0], 0);
        close(pd[0]);
        char s[MAX];
        while (fgets(s, sizeof(s), stdin)) printf("%s", s);
        return 0;
    }

    close(pd[0]);
    dup2(pd[0], 0);
    close(pd[0]);
    char *s = "Hello world\nToday is a great day!\n";
    write(pd[1], s, strlen(s));
    close(pd[1]);
    waitpid(pid, NULL, 0);

    return 0;

}