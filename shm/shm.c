#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define MAX 5
#define N 1000

int main() {

	int shmid, i;
	int *buf;
	
	shmid = shmget(45281, MAX*sizeof(int), IPC_CREAT|0600);
	if(shmid == -1){
		perror("Utworzenie sadfsdfasd");
		exit(1);
	}
	
	pid_t pid = fork();
	
	if(pid == 0) {
		buf = (int*)shmat(shmid, NULL, 0);
		
		char msg[] = "dupka";
		
		for(i = 0; i < MAX; i++) {
			buf[i] = msg[i];
		}
		
		printf("zapisano cos tam ");
		shmdt(buf);
	}
	
	if(pid > 0) {
		
		buf = (int*)shmat(shmid, NULL, 0);
		
		wait(NULL);

		printf("proces odebral cos takigo: ");
		for(i = 0; i < MAX; i++){
			printf("%c", buf[i]);
		}
		
		shmdt(buf);
		
		shmctl(shmid, IPC_RMID, (struct shmid_ds*)0);
		
	}

	exit(0);
}
