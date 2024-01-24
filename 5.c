#include <stdio.h>
#include <stdlib.h>

/*
gcc 5.c -o 5

2.3 
SequenceTree.c

Kolejne wywołania funkcji a1 razem z wartościami przez nie zwracanym
nie wiem jak zrobić żeby się wyswietlało a1,a2,a3,a4,a5.....
*/
    int i = 1;

    double a1(int n) {
        if (n == 0) {
            printf("a%d(%d) = %lf\n", i, n, 1.0);
            return 1.0;
        } else if (n == 1) {
            printf("a%d(%d) = %lf\n", i, n, 4.0);
            return 4.0;
        } else {
            double result = 2.0 * a1(n - 1) + 0.5 * a1(n - 2); 
            printf("a%d(%d) = %lf\n", i, n, result);
            return result;
        }
    }


int main(int argc, char* argv[]) {
    printf("sequencetree.c\n\n");
    
    a1(4);

    return 0;

}

