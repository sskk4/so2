#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <string.h>

struct buf{
	long type;
	char value[50];
};

int main() {
    printf("fork.c\n\n");
    
	int msgid, i;
	struct buf buf;
	pid_t pid1;
	
	msgid = msgget(1234, IPC_CREAT|0600);
	if(msgid == -1){
		perror("error: ");
		exit(1);
	}

	pid1 = fork();
	if(pid1 == -1)
	{
		perror("error: ");
		exit(1);
	}
	if(pid1 == 0){
		buf.type = 1;
		strcpy(buf.value, "haha");
		msgsnd(msgid, &buf, sizeof(buf.value, 0), 0);
		exit(0);
	} else {
		wait(NULL);
		msgrcv(msgid, &buf, sizeof(buf.value), 1, 0);
		printf("Proces macierzysty otrzymal komunikat: %s\n", buf.value);
	}


    exit(0);
}
