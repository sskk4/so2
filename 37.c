#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

/*
gcc  37.c -o 37 -Wall

Zad. 11.21 *

Zmodyfikować poprzedni program, tak, by kolejka utworzona przez klienta była dwukierunkowa, 
klient publiczną kolejką powinien przesyłać nazwę stworzonej przez siebie kolejki.
 Dalsza wymiana komunikatów powinna odbywać się poprzez kolejkę stworzoną przez klienta. 
 Klient kolejką tą powinien wysyłać polecenia, zadaniem serwera jest wykonywanie tych poleceń i odsyłanie wyników.

*/

int main(int argc, char *argv[]) {
    printf("ex21.c\n\n");

    pid_t pid = fork();

    if (pid == 0) { // serwer

        mkfifo("serwer.txt", 0777);

        int c_desc = open("klient.txt", O_RDONLY);

        char buf[11];
        read(c_desc, buf, 11);

        printf("Komunikat od klienta do serwera:\n%s\n", buf);

        int s_desc = open("serwer.txt", O_RDWR);

        char cmd[100];

        read(s_desc, cmd, 100);

        printf("Polecenie przeslane od klienta do serwera:\n%s\n", cmd);

        dup2(s_desc, 1);

        execlp(cmd, cmd, NULL);

    }

    pid_t pid2 = fork();

    if (pid2 == 0) { // klient

        mkfifo("klient.txt", 0777);

        int c_desc = open("klient.txt", O_WRONLY);

        write(c_desc, "klient.txt", 11);
        
        int s_desc = open("serwer.txt", O_RDWR);

        write(s_desc, "tty", 4);

        char bufor[1000];
        int bn;

        printf("Komunikat od serwera do klienta:\n");

        while ((bn = read(s_desc, bufor, 1000)) > 0) {
            printf("%s", bufor);
        }

        printf("\n");
    }

    wait(NULL);

    return 0;
}

