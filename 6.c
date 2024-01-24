#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
gcc 6.c -o 6

3.1.2
Fractions.c
funkcja która wypisuje ułamek wedle schematu 

printFraction((struct Fraction){2,0});  // NaN
printFraction((struct Fraction){0,2});  // 0
printFraction((struct Fraction){2,4});  // 1/2
printFraction((struct Fraction){-1,2}); // -1/2
printFraction((struct Fraction){1,-2}); // -1/2
printFraction((struct Fraction){4,-2}); // -2
printFraction((struct Fraction){5,-2}); // -2 1/2

4.1.6
bezpieczny odczyt z terminala bez możliwości przepełnienia bufora linii
*/

struct Fraction {
    int num, den;
};

void printFraction(struct Fraction x) {
    int a = x.num;
    int b = x.den;

    printf("(struct Fraction {%d, %d}) -> ", a, b);

    if (a*b > 0 && a < 0) {
        a *= (-1);
        b *= (-1);
    }

    if (a*b<0) {
        printf("-");

        if (a < 0) a *= -1;
        if (b < 0) b *= -1;
    }

    if (b == 0) printf("NaN\n");
    else if (a == 0) printf("0\n");
    else {
        if (b > a) printf("%d/%d\n", a, b);
        else {
            int nominator = a % b;
            int a_temp = a - nominator;
            int number = a_temp / b;

            if (nominator == 0) printf("%d\n", number);
            else printf("%d %d/%d\n", number, nominator, b);
        }
    }
}

int main(int argc, char* argv[]) {
    printf("printFractions.c\n\n");
    
    struct Fraction exampleFractions = {5,2};

    printFraction(exampleFractions);

}

