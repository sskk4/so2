#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
gcc 31.c -o 31

11.17 

Napisz program który tworzy trzy procesy - proces macierzysty i jego dwa procesy potomne. 
Pierwszy z procesów potomnych powinien zapisać do potoku napis „hello!", 
a drugi proces potomny powinien ten napis odczytać.
*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");

    int pdesk[2];

    if (pipe(pdesk) == -1) {
        perror("Error with pipe: ");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) {
        write(pdesk[1], "Komunikat", 10);
    }

    pid_t second_pid = fork();

    if (second_pid == 0) {
        char buf[10];

        read(pdesk[0], buf, 10);

        printf("Odczytano: $s\n", buf);
    }

    return 0;

}

