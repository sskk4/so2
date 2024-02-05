#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

  #define MAX 512

    int main() {
	int pdesk[2]; 
    char buffer[50];
 
 	if (pipe(pdesk) == -1){
		perror("Tworzenie potoku");
		exit(1);
	}
  
	if (fork() == 0){ 
        close(pdesk[0]);
		const char *message = "haha";
        write(pdesk[1], message, strlen(message) + 1);
        close(pdesk[1]);
        exit(0);
	}
	else { 
		close(pdesk[1]);
		read(pdesk[0], buffer, sizeof(buffer));
        printf("Proces macierzysty otrzymal komunikat: %s", buffer);
        close(pdesk[0]);
        wait(NULL);
    }

    exit(0);
   }