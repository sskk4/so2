#include <stdlib.h>
#include <stdio.h>

/*
gcc 1.c -o 1

InputOutput.c 
1.1.2 wypisz wartosc typu double, 
1.1.3 odczytaj i wypisz string przy pomocy scanf, 
1.1.4 odczytaj i wypisz string przy pomocy fgets
*/


int main(int argc, char* argv[]) {
    printf("InputOutput.c\n\n");
    
    double liczba;
    printf("double -> ");
    scanf("%lf", &liczba);
    printf("double value = %lf\n\n", liczba);

     getchar(); // Usunięcie zbędnego znaku nowej linii z bufora wejściowego

    char napis[100];
    printf("string -> ");
    scanf(" %99[^\n]", napis);
    printf("string: %s\n\n", napis);

     getchar();

    char napis2[100];
    printf("string -> ");
    fgets(napis2, sizeof(napis2), stdin);
    printf("string: %s\n\n", napis2);

    return 0;
}

