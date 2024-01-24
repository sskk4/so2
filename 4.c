#include <stdio.h>
#include <stdlib.h>

/*
gcc 4.c -o 4 

2.2.1 *
sequence.c
wyliczanie wartosci ciagu an przy pomocy trzech funkcji
a(0) = 1
a(1) = 4
a(n) = 2*a(n-1) + 0.5*a(n-2)

a1 - metoda dziel i zwyciężaj. 
analiza wywołania a1(4):

a1(4) = 2 * a1(3) + 0.5 * a1(2)

a1(3) = 2 * a1(2) + 0.5 * a1(1)

a1(2) = 2 * a1(1) + 0.5 * a1(0)

podstawiam a(1) = 4, a(0) = 1

a1(2) = 2 * 4 + 0.5 * 1 = 8.5

a1(3) = 2 * 8.5 + 0.5 * 4 = 17 + 2 = 19

a1(4) = 2 * 19 + 0.5 * 8.5 = 42.25

drzewo wywołań:
GPT WYGENEROWAŁ PEWNIE ŹLE EH

a1(4)
├── a1(3)
│   ├── a1(2)
│   │   ├── a1(1)
│   │   └── a1(0)
│   └── a1(1)
└── a1(2)
    ├── a1(1)
    └── a1(0)

*/
  double a1(int n) {
        if (n == 0){
            return 1.0;
        } else if (n == 1) {
            return 4.0;
        } else {
            return 2.0 * a1(n - 1) + 0.5 * a1(n - 2);
        }
    }

/*
a2 - metoda programowania dynamicznego z ramką trójzębną.

    r0  r1  r2
    |---|---|
    0   1   2   3   4       indeksy
    1   4   8.5 19  42.5
        |---|---|
        r0  r1  r2

analiza wywołania

a2(4)

n = 0 false
n = 1 false

r0 = 1
r1 = 4

i = 2
2 <= 4 TRUE
r2 = 2 * 4 + 0.5 * 1 = 8.5
r0 = 4
r1 = 8.5

i = 3
3 <= 4 TRUE
r2 = 2 * 8.5 + 0.5 * 4 = 19
r0 = 8.5
r1 = 19

i = 4
4 <= 4 TRUE
r2 = 2 * 19 + 0.5 * 8.5 = 42.25
r0 = 19
r1 = 42.25

i = 5
4 <= 5 FALSE

RETURN 42.25


*/

    double a2(int n) {
        if (n == 0){
            return 1.0;
        } else if (n == 1){
            return 4.0;
        } 

        double r0 = 1.0;
        double r1 = 4.0;
        double r2;

        for (int i = 2; i <= n; i++) {
            r2 = r1 * 2 + r0 * 0.5;
            r0 = r1;
            r1 = r2;
        }

        return r1;
    }

int main(int argc, char* argv[]) {
    printf("sequence.c\n\n");
    
    int n = 4;

    printf("a1(%d) = %.2f\n\n", n, a1(n));
    printf("a2(%d) = %.2f\n", n, a2(n));

    return 0;
}

