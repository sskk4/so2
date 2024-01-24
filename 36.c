#include <stdio.h>
#include <stdlib.h>

/*
gcc 
11.20 

Napisz program tworzący dwa procesy: klienta i serwera. 
Serwer tworzy ogólnodostępną kolejkę FIFO, i czeka na zgłoszenia klientów. 
Każdy klient tworzy własną kolejkę, poprzez którą będą przychodzić odpowiedzi serwera. 
Zadaniem klienta jest przesłanie nazwy stworzonej przez siebie kolejki, 
a serwera odesłaniem poprzez kolejkę stworzoną przez klienta wyniku polecenia ls. 

*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    pid_t pid = fork();

    if (pid == 0) {

        mkfifo("serwer.txt", 0777);

        int c_desc = open("klient.txt", O_RDONLY);

        char buf[11];
        read(c_desc, buf, 11);

        printf("Komunikat od klienta do serwera: \n $s \n", buf);

        int s_desc = open("serwer.txt", O_WRONLY);

        dup2(s_desc, 1);

        execlp("ls", "ls", NULL);
    }

    pid_t pid2 = fork();

    if (pid2 == 0) {

        mkfifo("klient.txt", 0777);

        int c_desc = open("klient.txt", O_WRONLY);

        write(c_desc, "klient.txt", 11);

        int s_desc = open("serwer.txt", O_RDONLY);

        char bufor[1000];
        int bn;

        printf("Komunikat od serwera do klienta: \n");

        while ((bn = read(s_desc, bufor, 1000)) > 0) {
            printf("%s", bufor);
        }

        printf("\n");
    }

    wait(NULL);

    return 0;

}

