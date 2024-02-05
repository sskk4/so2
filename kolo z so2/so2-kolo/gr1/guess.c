#include <stdio.h>
#include <stdlib.h>


/*

Napisz program guess wyznaczający przybliżony czas kolejnego cyklu CPu przy pomocy średnieej wykładniczej dla t=10 i a =0.5 
przykładowa sesja:
burst: 6 4 6 4 13 13 13
guess: 10 8 6 6 5 9 11
*/

void exponentialAverage(int burst[], int size, double t, double a) {
    double average = 0.0;
    double lastCycleTime = t;

    printf("burst:\t");
    for (int i = 0; i < size; i++) {
        printf("%d ", burst[i]);
    }

    printf("\nguess:\t");
    for (int i = 0; i < size; i++) {
        average = (1 - a) * lastCycleTime + a * burst[i];
        printf("%.0f ", average);
        lastCycleTime = average;
    }

    printf("\n");
}

int main() {
    printf("guess.c\n\n");

    int burst[] = {6, 4, 6, 4, 13, 13, 13};
    int size = sizeof(burst) / sizeof(int);

    double t = 10.0;  // Średni czas cyklu CPU
    double a = 0.5;   // Współczynnik wygładzania

    exponentialAverage(burst, size, t, a);

    return 0;
}