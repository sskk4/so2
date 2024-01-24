#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

/*
gcc 25.c -o 25

10.5
Napisz program fork5 w którym proces dziecko wyświetla własny pid oraz pid rodzica. Przykładowa sesja:

Poczatek
Koniec
Proces dziecko, pid dziecka = 3257
Proces dziecko, pid rodzica = 3256
Koniec

*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    printf("Poczatek\n");

    pid_t pid = fork();

    if (pid < 0) fprintf(stderr, "Blad tworzenia procesu potomnego.\n");

    if (pid == 0) {
        printf("Proces dziecko, pid dziecka = %d\n", getpid());
        printf("Proces dziecko, pid rodzica = %d\n", getppid());
    }

    printf("Koniec\n");

    return 0;
}

