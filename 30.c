#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*
gcc 30.c -o 30

11.2 
Napisz program psize2 wypisujący maksymalną liczbę bajtów, które można zapisać atomowo do potoku.
*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    int pdesk[2];

    if(pipe(pdesk) == -1) {
        perror("Blad tworzenia potoku ");
        exit(1);
    }

    int psize = fcntl(pdesk[1],  F_GETPIPE_SZ);

    printf("Max atomic write size to the pipe = %d\n", psize);

    return 0;

}

