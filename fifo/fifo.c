#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX 512

int main() {
    int pdesk, i;
    
    if (access("/tmp/fifo", F_OK) == -1) {
        if (mkfifo("/tmp/fifo", 0600) == -1) {
            perror("Tworzenie kolejki FIFO");
            exit(1);
        }
    }
	
	if(fork() == 0){
		close(1);
		
		pdesk = open("/tmp/fifo", O_WRONLY);
		if(pdesk == -1){
			perror("otwarto potok do zapisu");
			exit(1);
		}
		
		int nums[] = {10,10,10,10};
		
		for(i = 0; i < 4 ; i++){
		
		if(write(pdesk, &nums[i], sizeof(int)) == -1){
			perror("bladkafdk");
			exit(1);
		}
		
	}
		close(pdesk);
	} else {
			
			pdesk = open("/tmp/fifo", O_RDONLY);
		if(pdesk == -1){
			perror("otwarto potok do zapisu");
			exit(1);
		}
		int buf[10];
		int sum = 0;
		for(i = 0; i < 4; i++){

			if(read(pdesk, &buf[i], sizeof(int)) == -1){
				perror("bladkafhahahaahahadk");
				exit(1);
			}
			
			sum += buf[i];
				}
				
							close(pdesk);
			printf("suma: %d", sum);

	}
	
	unlink("/tmp/fifo");

    
    return 0;
}

