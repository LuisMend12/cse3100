#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *compute_sum(void *arg) {
    int n = *(int *) arg;
    int *result = malloc(sizeof(int));
    *result = 0;

    for (int i = 1; i <= n; i++) *result += 1;

    pthread_exit(result);
}

int main() {
     pthread_t thread;
     int n = 10;
     int *result;
     if (pthread_create(&thread, NULL ,compute_sum, &n)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
     }
     if (pthread_join(thread, (void**)&result)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
     }

     printf("Sum of first %d natural numbesr: %d\n", n, *result);

     free(result);

     return 0;
}