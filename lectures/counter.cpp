#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long count = 0;

void *increase(void *arg) {
    long i, inc = *(long *) arg;

    for (int i = 0; i < inc; i++) {
        count ++;
    }
    pthread_exit(NULL);
}


int main(int argc, char *argv[]) {
    pthread_t tid1, tid2;
    long inc = atol(argc >= 2 ? argv[1] : "100");

    pthread_create(&tid1, NULL, increase, &inc);
    pthread_create(&tid2, NULL, increase, &inc);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("conuter is %ld\n", count);
    return 0;
}