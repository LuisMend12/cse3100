#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* print out an error message and exit */
void my_error(char *s)
{
    perror(s);
    exit(1);
}

/* Concatnate two strings.
 * Dynamically allocate space for the result.
 * Return the address of the result.
 */
char *my_strcat(char *s1, char *s2)
{
    const char *prefix = "./argvcat";
    char* result = malloc(strlen(prefix) + strlen(s1) + strlen(s2) + 1);
    if(!result) my_error("Memory allocation failed!");
    
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main(int argc, char *argv[])
{
    char *s = malloc(1);
    if(!s) my_error("Memory allocation failed!");
    s[0] = '\0';
    for (int i = 1; i < argc; i ++) {
        char* temp = my_strcat(s, argv[i]);
        free(s);
        s = temp;
    }

    printf("./argvcat%s\n", s);
    free(s);
    return 0;
}