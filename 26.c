#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
gcc 26.c -o 26

10.8
przepisz i przeanalizuj xd
*/

int main(int argc, char* argv[]) {
    printf("Poczatek\n");

    pid_t pid = fork();

    if (pid == -1) {
        perror("Blad tworzenia procesu potomnego");

        return 1;
    }

    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);

        perror("Blad uruchomienia programu");
        exit(1);
    }

    if (wait(NULL) == -1)
        perror("Blad w oczekiwaniu na zakonczenie potomka");
        
        printf("Koniec\n");

        return 0;
    
    return 0;

}

