#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY 1234
#define MSG_SIZE  sizeof(int)

struct MsgBuffer {
    long mtype;  // Typ komunikatu
    int mdata;   // Dane komunikatu
};

int main() {
    int msgQueueId;
    struct MsgBuffer msgBuffer;
    pid_t childPid;

    // Tworzenie kolejki komunikatów
    msgQueueId = msgget(KEY, IPC_CREAT | 0666);
    if (msgQueueId == -1) {
        perror("Nie można utworzyć kolejki komunikatów");
        exit(1);
    }

    // Tworzenie procesu potomnego
    childPid = fork();

    if (childPid == -1) {
        perror("Błąd w funkcji fork");
        exit(1);
    }

    if (childPid == 0) {  // Proces dziecko
        int numbers[] = {1, 2, 3, 4, 5};

        for (int i = 0; i < 5; i++) {
            // Wysyłanie liczb do procesu rodzica
            msgBuffer.mtype = 1;
            msgBuffer.mdata = numbers[i];
            msgsnd(msgQueueId, &msgBuffer, MSG_SIZE, 0);
        }

        exit(0);
    } else {  // Proces rodzic
        int sum = 0;

        for (int i = 0; i < 5; i++) {
            // Odbieranie liczb od procesu dziecka
            msgrcv(msgQueueId, &msgBuffer, MSG_SIZE, 1, 0);
            sum += msgBuffer.mdata;
        }

        // Wypisanie sumy na konsoli
        printf("Suma liczb przesłanych przez dziecko: %d\n", sum);

        // Usunięcie kolejki komunikatów
        msgctl(msgQueueId, IPC_RMID, NULL);

        exit(0);
    }

    return 0;
}