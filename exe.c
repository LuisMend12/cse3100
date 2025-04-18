#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;
  int status;
  pid = fork();
  if (pid == -1) {
    printf("can't fork, error occurred\n");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    printf("child process, pid = %u\n", getpid());

    char *argv_list[] = {"./test", NULL};

    execv(*argv_list, argv_list);
    exit(-1);
  } else {
    printf("parent process, pid = %u\n", getppid());
    waitpid(pid, &status, 0);
    printf("WIFEXITED = %d, WEXITSTATUS = %d\n", WIFEXITED(status),
           WEXITSTATUS(status));
  }
  return 0;
}