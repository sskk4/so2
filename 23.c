#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*
gcc 23.c -o 23

Zad. 9.7 *

Napisz program, który w pliku o nazwie podanej jako ostatni argument 
zapisze połączoną zawartość wszystkich plików, 
których nazwy zostały podane w linii poleceń przed ostatnim argumentem.

*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    if (argc <= 2){
        printf("As arguments you will input list of files and destination file.\n");
        exit(1);
    }

    int dest = creat(argv[argc-1], 0777);

    if (dest == -1) {
        perroor("Error: ");
        exit(1);
    }

    int i;
    for (i = 1; i < argc-1; i++) {
        int cur = open(argv[i], O_RDONLY);

        if (cur == -1) {
            perroor("Error: ");
            exit(1);
        }

        char buf[100];
        int readed;

        while ((readed = read(cur, buf, 100)) > 0) {
            write(dest, buf, readed);
        }

        if (close(cur) == -1) {
            perror("Error: ");
            exit(1);
        }

    }

    if (close(dest) == -1){
        perror("Error: ");
        exit(1);
    }

    exit(0);
}

