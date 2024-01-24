#include <stdio.h>
#include <stdlib.h>

/*
gcc 

10.16 
Napisz program tworzący dwa procesy. Każdy ze stworzonych procesów powinien utworzyć proces - potomka. 
Należy wyświetlać identyfikatory procesów rodziców i potomków po każdym wywołaniu funkcji fork.

*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    fork();

    printf("Pierwszy fork - pid = %d\n", getpid());
    printf("Pierwszy fork - ppid = %d\n", getppid());

    fork();

    printf("Drugi fork - pid = %d\n", getpid());
    printf("Pierwszy fork - ppid = %d\n", getppid());

    return 0;
}

