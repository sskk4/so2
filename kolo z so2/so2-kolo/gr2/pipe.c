#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    int pdesk[2];
    pid_t pid;

    if (pipe(pdesk) == -1) {
        perror("Blad przy tworzeniu potoku");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("Blad przy tworzeniu procesu potomnego");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Proces dziecko
        close(pdesk[0]); // Zamykamy końcówkę do odczytu, nie będzie nam potrzebna
        int numbers[] = {1, 2, 3, 4, 5};

        write(pdesk[1], numbers, sizeof(numbers));
        close(pdesk[1]); // Zamykamy końcówkę do zapisu, sygnalizujemy koniec przesyłania
    }

    if (pid > 0) {
        // Proces rodzic
        close(pdesk[1]); // Zamykamy końcówkę do zapisu, nie będzie nam potrzebna
        int numbers[5];
        read(pdesk[0], numbers, sizeof(numbers));
        close(pdesk[0]); // Zamykamy końcówkę do odczytu, sygnalizujemy koniec odczytu

        // Wyliczanie iloczynu
        int product = 1;
        for (int i = 0; i < 5; i++) {
            product *= numbers[i];
        }

        // Wypisanie iloczynu
        printf("Iloczyn liczb: %d\n", product);
    }

    return 0;
}
