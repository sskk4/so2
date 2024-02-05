#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX 80

/*

najpierw uruchom fwriter później freader */

int main() {
    int fdesc = open("kolFIFO", O_RDONLY);

    if(fdesc == -1){
        perror("Blad otwarcia kolejki do odczytu");
    }

    printf("freader : fdesc = %d\n", fdesc);

    char buf[MAX];

    read(fdesc, buf, MAX);

    printf("Message received: %s\n", buf);

    return 0;
}