#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*
gcc 38.c -o 38 -Wall -lpthread

14.6 *

Napisz program thread-calc ilustrujący dwa wątki.
Pierwszy pobiera tablicę liczb i zwraca minimum i maksimum z tej tablicy,
a drugi zwraca średnią elementów z tablicy.
*/

int tab[] = {1, 2, 3, 4, 5, 6};

void *sum(void *arg) {
    long size = (long)arg;

    long suma = 0;

    int i;
    for(i = 0; i < size; i++) {
        suma = suma + tab[i];
    }

    long *result = malloc(sizeof(long));
    *result = suma;

    return (void *)result;
}

void *mean(void *arg) {
    long size = (long)arg;
    float suma = 0

   int i;
    for (i = 0; i < size; i++) {
        suma = suma + tab[i];
    }

    suma /= size;

    float *result = malloc(sizeof(float));
    *result = suma;

    return result;
}

int main() {
    int size = sizeof(tab) / sizeof(int);

    pthread_t thread_sum;
    pthread_t thread_mean;

    if (pthread_create(&thread_sum, NULL, sum, (void *)(long)size)) {
        printf("Blad przy tworzeniu watku.\n");
        abort();
    }

    if (pthread_create(&thread_mean, NULL, mean, (void *)(long)size)) {
        printf("Blad przy tworzeniu watku.\n");
        abort();
    }

    long *suma;
    float *srednia;

    printf("Proces czeka na zakonczenie watku.\n");

    if (pthread_join(thread_sum, (void **)&suma)) {
        printf("Blad przy konczeniu watku.\n");
        exit(1);
    }

    if (pthread_join(thread_mean, (void **)&srednia)) {
        printf("Blad przy konczeniu watku.\n");
        exit(1);
    }

    printf("suma = %ld\n", *suma);
    printf("srednia = %lf\n", *srednia);

    free(suma);
    free(srednia);

    exit(0);
}