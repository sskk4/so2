#include <stdio.h>
#include <stdlib.h>

/*
gcc 28.c -o 28 -Wall
ps -e -o pid,ppid,comm,stat

10.17 
Napisz program tworzący równocześnie trzy procesy zombie.

*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    int pid;

    pid = fork();
    if(pid = 0) {
        printf("1. zombie pid = %d\n", getpid());
        exit(0);
    }
    
    pid = fork();
    if(pid = 0) {
        printf("2. zombie pid = %d\n", getpid());
        exit(0);
    }

    pid = fork();
    if(pid = 0) {
        printf("3. zombie pid = %d\n", getpid());
        exit(0);
    }

    sleep(20);

    wait(NULL);

    exit(0);

    return 0;

}

