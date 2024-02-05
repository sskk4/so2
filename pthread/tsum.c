#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define ARRAY_SIZE 10000000 // Rozmiar tablicy bajtów (10 MB)
#define NUM_THREADS 2

unsigned char *byte_array; // Tablica bajtów
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 

struct thread_args {
    int start;
    int end;
    long sum;
};

void *add(void *arg) {
    struct thread_args *args = (struct thread_args *)arg;
    int start = args->start;
    int end = args->end;

	int i;
    for (i = start; i < end; i++) {
        args->sum += byte_array[i];
    }

    pthread_exit(NULL);
}

int main() {

    byte_array = malloc(ARRAY_SIZE);
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        byte_array[i] = rand() % 256; 
    }

    pthread_t threads[NUM_THREADS];
    struct thread_args args[NUM_THREADS];


    for (i = 0; i < NUM_THREADS; i++) {
        args[i].start = i * (ARRAY_SIZE / NUM_THREADS);
        args[i].end = (i + 1) * (ARRAY_SIZE / NUM_THREADS);
        args[i].sum = 0;
    }

    clock_t start_time, end_time;

    // W¹tek g³ówny
    start_time = clock();

    long main_thread_sum = 0;
    for (i = 0; i < ARRAY_SIZE; i++) {
        main_thread_sum += byte_array[i];
    }

    end_time = clock();

    double main_thread_time = ((double)end_time - start_time) / CLOCKS_PER_SEC;

    // W¹tki poboczne
    start_time = clock();

    pthread_t thread_ids[NUM_THREADS];
    for ( i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&thread_ids[i], NULL, add, (void *)&args[i])) {
            perror("B³¹d przy tworzeniu w¹tku.");
            exit(EXIT_FAILURE);
        }
    }
    for ( i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(thread_ids[i], NULL)) {
            perror("B³¹d przy koñczeniu w¹tku.");
            exit(EXIT_FAILURE);
        }
    }

    long multi_thread_sum = 0;
    for (i = 0; i < NUM_THREADS; i++) {
        multi_thread_sum += args[i].sum;
    }

    end_time = clock();

    double multi_thread_time = ((double)end_time - start_time) / CLOCKS_PER_SEC;

    // Wyniki
    printf("sum1: %ld\n", main_thread_sum);
    printf("sum2: %ld\n", multi_thread_sum);
    
    printf("\nsum1 time: %lf\n", main_thread_time);
	printf("sum2 time: %lf\n", multi_thread_time);

    free(byte_array);

    return 0;
}

