#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
gcc 33.c -o 33

11.19
ls | wc
*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    int pdesk[2];

    pipe(pdesk);

    pid_t pid = fork();

    if(pid == 0) {
        close(pdesk[0]);

        dup2(pdesk[1], 1);

        execlp("ls", "ls", NULL);
    }

    if (pid != 0) {
        close(pdesk[1]);

        wait(NULL);

        dup2(pdesk[0], 0);

        execlp("wc", "wc", NULL);
    }

    return 0;

}

