    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <string.h>
    #include <sys/msg.h>


    struct buf_elem {
	long mtype;
	int mvalue;
   };

    int main(){
	int msgid;
	struct buf_elem elem;
    int i;

	msgid = msgget(1234, IPC_CREAT|0600);
	if (msgid == -1){
 		if (msgid == -1){
			perror("tworzenie kolejki komunikator error:");
			exit(1);
 		}
	}

    pid_t pid1 = fork();

    if(pid1 == -1) {
        perror("tworzenie procesu error:");
        exit(1);
    } 

    if(pid1 == 0) {
        int nums[] = {1, 2, 3, 4, 5};

        for(i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
            elem.mtype = 1;
            elem.mvalue = nums[i];
            msgsnd(msgid, &elem, sizeof(int), 0);
        }
        exit(0);
    } else {
        int sum = 0;
        for(i = 0; i < 5; i++){
            msgrcv(msgid,&elem, sizeof(int), 1, 0);
            sum += elem.mvalue;
        }

        printf("wynik: %d\n", sum);
        wait(NULL);
    }
	
    exit(0);

   } 