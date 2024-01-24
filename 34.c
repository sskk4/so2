#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
gcc 34.c -o 34

11.19
ls -l | grep ^d | more
*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    int pdesk[2];

    pipe(pdesk);

    pid_t pid = fork();
    if (pid == 0) {
        
        pid_t pid2 = fork();

        if (pid2 == 0) {
            close(pdesk[0]);

            dup2(pdesk[1], 1);

            execlp("ls", "ls", NULL);
        }

        if (pid2 != 0) {
            wait(NULL);

            dup2(pdesk[0], 0);

            execlp("grep", "grep", "^e", NULL);
        }
    }

    if (pid != 0) {
        wait(NULL);
        
        close(pdesk[1]);

        execlp("more", "more", NULL);
    }

    return 0;

}

