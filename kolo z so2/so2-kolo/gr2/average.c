#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int burstTime;
};

double avgWaitingTime(struct Process p[], int size) {
    int sum = 0;
    int curTime = 0;

    int i;
    for (i = 0; i < size; i++) {
        sum += curTime;
        curTime += p[i].burstTime;
    }

    double avg = sum / size;

    return avg;
}

void swap(struct Process *p1, struct Process *p2) {
    struct Process tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void applySJF(struct Process p[], int size) {
    int i;
    int k;

    for (i = 0; i < size; i++) {
        for (k = 0; k < size - 1; k++) {
            if (p[k].burstTime > p[i].burstTime) {
                swap(&p[i], &p[k]);
            }
        }
    }
}

int main() {
    printf("scheduler.c\n\n");

     struct Process p[] = {
         {1, 6},
         {2, 8},
         {3, 7},
         {4, 3}
     };


    int size = sizeof(p) / sizeof(struct Process);


    double avgTime = avgWaitingTime(p, size);

    printf("average1 = %f\n", avgTime); //fcfs

    applySJF(p, size);

    avgTime = avgWaitingTime(p, size);

    printf("average2: %f\n", avgTime); //sjf


    return 0;
}
