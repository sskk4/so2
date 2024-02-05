#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int burstTime;
};

void burstTime(struct Process p[], int size) {
    int i;

    printf("ID\tBurst\n");

    for (i = 0; i < size; i++) {
        printf("%d\t%d\n", p[i].id, p[i].burstTime);
    }
}

void waitingTime(struct Process p[], int size) {
    int curTime = 0;

    printf("ID\tBurst\tWait\n");

    int i;
    for (i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", p[i].id, p[i].burstTime, curTime);

        curTime += p[i].burstTime;
    }
}

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
         {1, 24},
         {2, 3},
         {3, 3}
     };

//     struct Process p[] = {
//         {2, 3},
//         {3, 3},
//         {1, 24}
//     };

//    struct Process p[] = {
//        {1, 6},
//        {2, 8},
//        {3, 7},
//        {4, 3}
//    };


    int size = sizeof(p) / sizeof(struct Process);

// test burstTime
    printf("burstTime test\n\n");

    burstTime(p, size);

    printf("\n\n");

// test waitingTime
    printf("waitingTime test\n\n");

    waitingTime(p, size);

    double avgTime = avgWaitingTime(p, size);

    printf("\nAverage waiting time = %f", avgTime);

    printf("\n\n");

// test SJF
    printf("SJF test\n\n");

    applySJF(p, size);

    burstTime(p, size);

    printf("\n\n");

    return 0;
}
