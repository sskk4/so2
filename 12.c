#include <stdio.h>
#include <stdlib.h>

/*
gcc 12.c -o 12
7.2
program wypisujący nazwę programu
*/

int main(int argc, char* argv[]) {
    printf("arguments.c\n\n");
    
    if (argc > 0) {
        printf("Nazwa programu: %s\n", argv[0]);
    } else {
        printf("Brak nazwy programu.\n");
    }

    return 0;

}

