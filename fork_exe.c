// C program to illustrate use of fork() & 
// exec() system call for process creation 

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/wait.h> 

int main(){ 
    pid_t pid; 
    int status; 
    pid = fork(); 
    if (pid == -1){ 

        // pid == -1 means error occurred 
        printf("can't fork, error occurred\n"); 
        exit(EXIT_FAILURE); 
    } 
    else if (pid == 0){ 

        // pid == 0 means child process created 
        // getpid() returns process id of calling process 
        printf("child process, pid = %u\n",getpid()); 

        // the argv list first argument should point to 
        // filename associated with file being executed 
        // the array pointer must be terminated by NULL 
        // pointer 
        char * argv_list[] = {"./fork-treasure-hunt","10",NULL}; 
    
        // the execv() only return if error occurred. 
        // The return value is -1 
        execv("./fork-treasure-hunt",argv_list); 
        exit(-1); 
    } 
    else{ 
        // a positive number is returned for the pid of 
        // parent process 
        // getppid() returns process id of parent of 
        // calling process 
        printf("parent process, pid = %u\n",getppid()); 

        // the parent process calls waitpid() on the child 
        // waitpid() system call suspends execution of 
        // calling process until a child specified by pid 
        // argument has changed state 
        // see wait() man page for all the flags or options 
        // used here 
        if (waitpid(pid, &status, 0) > 0) { 
            
            if (WIFEXITED(status) && !WEXITSTATUS(status)) 
            printf("program execution successfull\n"); 
            
            else if (WIFEXITED(status) && WEXITSTATUS(status)) { 
                if (WEXITSTATUS(status) == 127) { 

                    // execv failed 
                    printf("execv failed\n"); 
                } 
                else
                    printf("program terminated normally,"
                    " but returned a non-zero status\n");                 
            } 
            else
            printf("program didn't terminate normally\n");             
        } 
        else { 
        // waitpid() failed 
            printf("waitpid() failed\n"); 
        } 
        exit(0); 
    } 
    return 0; 
} 
