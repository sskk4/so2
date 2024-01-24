#include <stdio.h>
#include <stdlib.h>

/*
gcc 18.c -o 18
8.2
6
perrorExample
*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    FILE *fp = fopen("file.txt", "r");

    if (fp == NULL) {
        perror('blad otwarcia pliku');
        return EXIT_FAILURE;
    }

    fclose(fp);

    return 0;

}

