#include <stdio.h>
#include <math.h>

/*
gcc 13.c -o 13 -lm

7.4
 program cyfry wyliczający liczbę cyfr danej liczby całkowitej przy pomocy funkcji

 funkcja cyfry1 wykorzystuje funkcję log10.
*/

int cyfry1(int liczba) {
    if (liczba == 0) {
        return 1;
    }

    return (int)log10(fabs(liczba)) + 1;
}

/*
funkcja cyfry3 wykorzystuje dzielenie przez 10. 
*/

int cyfry3(int liczba) {
    if (liczba == 0) {
        return 1;
    }

    int liczbaCyfr = 0;

    while (liczba != 0) {
        liczba /= 10;
        liczbaCyfr++;
    }

    return liczbaCyfr;
}

int main(int argc, char* argv[]) {
    printf("cyfry.c\n\n");
    
    printf("(cyfry1): %d\n", cyfry1(1000));
    printf("(cyfry3): %d\n", cyfry3(1000));

    return 0;

}

