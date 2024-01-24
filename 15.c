#include <stdio.h>
#include <stdlib.h>

/*
gcc 15.c -o 15

7.6
dodawanie.c
dodawanie pisemne

do dopracowania bo wyświetla takie 
   1 11
   0999
+  0002
------
0000001001
*/

void dodawanie(int a, int b) {
    int wynik[10] = {0};
    int przeniesienie = 0;

    printf("   1 11\n");
    printf("   %04d\n", a);
    printf("+  %04d\n", b);
    printf("------\n");

    for (int i = 9; i >= 0; i--) {
        int suma = a % 10 + b % 10 + przeniesienie;
        wynik[i] = suma % 10;
        przeniesienie = suma / 10;

        a /= 10;
        b /= 10;
    }

    for (int i=0; i < 10; i++) {
        printf("%d", wynik[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    printf("dodawanie.c\n\n");
    
    int a, b;

    printf("a ->");
    scanf("%d", &a);

    printf("b ->");
    scanf("%d", &b);

    dodawanie(a, b);

    return 0;
}

