#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/*
11.12
program ilustrujacy zapis do koljeki FIFO.

dlaczego i na jakiej funkcji program sie blokuje

Jeśli nie istnieje drugi koniec potoku (czytelnik) i potok 
nie został otwarty do czytania przed uruchomieniem programu fwriter,
 to funkcja open może się zablokować w oczekiwaniu na drugi koniec potoku.
*/

int main() {

    if (mkfifo("kolFIFO",0600) == -1){
        perror("Blad tworzenia kolejki FIFO");
        exit(1);
    }

    int fdesc = open("kolFIFO", O_WRONLY);

    if (fdesc == -1){
        perror("Blad otwarcia kolejki do zapisu");
        exit(1);
    }

    printf("fwriter : fdesc = %d\n", fdesc);

    char msg[] = "Message from fwriter";
    write(fdesc, msg, strlen(msg) + 1);
    
    printf("Message sent: %s\n", msg);

    return 0;
}