#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define ARRAY_SIZE 10000000  // 10 MB
#define NUM_THREADS 2

unsigned char array[ARRAY_SIZE];

// Struktura do przechowywania danych dla wątków pobocznych
struct ThreadData {
    int start;
    int end;
    unsigned int sum;
};

// Funkcja sumująca dla wątków pobocznych
void *add(void *data) {
    struct ThreadData *threadData = (struct ThreadData *)data;

    for (int i = threadData->start; i < threadData->end; i++) {
        threadData->sum += array[i];
    }

    return NULL;
}

// Funkcja sumująca w wątku głównym
unsigned int sumInMainThread() {
    unsigned int sum = 0;
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }

    return sum;
}

int main() {
    srand(time(NULL));

    // Inicjalizacja losowej tablicy bajtów
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 256;
    }

    clock_t start, end;

    // Pomiar czasu dla sumowania w wątku głównym
    start = clock();
    unsigned int sum1 = sumInMainThread();
    end = clock();
    double time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("sum1 = %u\n", sum1);
    printf("sum1 time = %.6lf\n", time1);

    // Pomiar czasu dla sumowania za pomocą dwóch wątków pobocznych
    start = clock();
    pthread_t threads[NUM_THREADS];
    struct ThreadData threadData[NUM_THREADS];
    
    int interval = ARRAY_SIZE / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].start = i * interval;
        threadData[i].end = (i + 1) * interval;
        threadData[i].sum = 0;
        
        pthread_create(&threads[i], NULL, add, (void *)&threadData[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    unsigned int sum2 = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        sum2 += threadData[i].sum;
    }

    end = clock();
    double time2 = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("sum2 = %u\n", sum2);
    printf("sum2 time = %.6lf\n", time2);

    return 0;
}