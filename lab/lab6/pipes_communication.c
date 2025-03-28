int main(int argc, char* argvp[]) {
    int fd[2];
    if (pipe(fd) == -1) {printf("An error ocurred with opening the pipe \n"); return 1;}

    int id = fork();
    if (id == -1) {printf("An error ocurred with fork\n"); return 2;}
    if (id == 0) { close(fd[0]); int x; printf("Input a number: "); scanf("%d", &x); write(fd[1], &x, sizeof(int)); if (write(fd[1], &x, sizeof(int) == -1)) { printf("An error has occured with writing to the pipe\n"); return 2; }; close(fd[1]);}
    else { int y; read(fd[0], &y, sizeof(int)); printf("Got from child process %d\n", y); if (read(fd[1], &y, sizeof(int) == -1)) printf("An error has ocurred with reading to the pipe\n"); return 3; close(fd[0]); printf("Got from the child process %d\n", y); }
    /* Intro to pipes, they have file descriptors*/
    pipe(fd);
    return 0;
}  