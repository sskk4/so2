#include <stdio.h>
#include <stdlib.h>


void avg(int burst[], int size, double t, double a) {
	double average = 0.0;
	double lastCycleTime = t;
	
	printf("burst:\t");
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", burst[i]);
	}
	
	printf("\nguess:\t");
	for (i = 0; i < size; i++) {
		average = (1 - a) * lastCycleTime + a * burst[i];
		printf("%.0f ", average);
		lastCycleTime = average;
	}
	
	printf("\n");
	
}

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    int burst[] = {6, 4, 6, 4, 13, 13, 13};
    int size = sizeof(burst) / sizeof(int);
    
    double t = 10.0;
    double a = 0.5;
    
    avg(burst, size, t, a);
    
    return 0;
}

