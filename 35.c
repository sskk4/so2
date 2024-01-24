#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
gcc 35.c -o 35

19.11
cat /etc/group | head -5 > grupy.txt
*/

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    int pdesk[2];

    pipe(pdesk);

    pid_t pid = fork();

    if(pid = 0) {
        close(pdesk[0]);
        dup2(pdesk[1], 1);

        execlp("cat", "cat", "/etc/group", NULL);
    }

    wait(NULL);

    pid = fork();

    if(pid == 0) {
        dup2(pdesk[0], 0);

        int desk = creat("grupy.txt", 0777);

        dup2(desk, 1);

        execlp("head", "head", "-5", NULL);
    }

    wait(NULL);

    return 0;

}

