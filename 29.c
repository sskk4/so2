#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*
gcc 29.c -o 29 -Wall

10.18 
Napisz program, którego rezultatem będzie wydruk zawartości 
bieżącego katalogu poprzedzony napisem Poczatek a zakończony napisem Koniec.

*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    printf("Poczatek.\n");

    pid_t pid = fork();

    if (pid == 0) {

        execlp("ls", "ls", NULL);

        perror("Blad uruchomienia programu");

        exit(1);
    }

    wait(NULL);

    printf("Koniec.\n");

    return 0;

}

