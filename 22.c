#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>

/*
gcc 22.c -o 22

Zad. 9.6 *

Napisz program do rozpoznawania czy plik o podanej nazwie jest plikiem tekstowym, 
plik tekstowy zawiera znaki o kodach 0-127, można w tym celu użyć funkcji isascii.
*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    int fd = open("base.txt", O_RDONLY);

    if(fd == -1) {
        perror("Error: ");
        exit(1);
    }

    char bufor[1];
    int i = 1;
    while (bufor[0] != '\0') {
        lseek(fd, i, SEEK_SET);
        read(fd, bufor, 1);

        if(!isasci(bufor[0])) {
            printf("This is not txt");
            break;
        }

        i++;
    }

    printf("This is txt file");

    if(close(fd) == -1) {
        perror("Error: ");
        exit(1);
    }

    exit(0);

}

