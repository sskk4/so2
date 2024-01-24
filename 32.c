#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
gcc 32.c -o 32 -Wall

11.18 

Napisz program, który tworzy trzy procesy, 
z których dwa zapisują do potoku, 
a trzeci odczytuje z niego i drukuje otrzymane komunikaty.

*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    int pdesk[2];

    if(pipe(pdesk) == -1) {
        perror("Error with pipe: ");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) {
        write(pdesk[1], "Komunikat", 10);
    }

    pid_t second_pid = fork();
    if(second_pid == 0){
        write(pdesk[1], "Komunikat2", 11);
    }

    pid_t third_pid = fork();

    if(third_pid == 0) {
        char text[50];

        read(pdesk[0], text, 50);

        printf("Odczytano: %s\n", text);
    }

    return 0;

}

