#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
gcc 9.c -o 9 

5.2.2
 program CountWords odczytujący plik tekstowy oraz obliczający liczbę słów 
 w tym pliku przy pomocy funkcji countWords2, 
 która oblicza liczbę słów bez pomocy zmiennej stanu.


 nie jestem pewny tego isspace??????
 
*/ 

int countWords2(FILE *fp) {
    int count = 0;
    int inWord = 0;
    int c;

    while((c = fgetc(fp)) != EOF) {
        if (isspace(c)) {
            if (inWord) {
                count++;
                inWord=0;
            }
        } else {
            if(!inWord) {
                inWord = 1;
            }
        }
    }

    if (inWord) {
        count++;
    }

    return count;
}

int main(int argc, char* argv[]) {
    printf("CountWords.c\n\n");
    
    const char name[] = "file.txt";

    FILE* fp = fopen(name, "r");

    if (fp == NULL){
        perror(name);

        return EXIT_FAILURE;
    }

    printf("liczba slow: %d\n", countWords2(fp));

    return 0;

}

