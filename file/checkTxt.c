#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
// 9.6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("checkTxt.c\n\n");

    int fd = open("checkTxt.exe", O_RDONLY);

    if (fd == -1) {
        perror("Error: ");
        exit(1);
    }

    char bufor[1];
    int i = 0;
    while (read(fd, bufor, 1) > 0) {
        if (!isascii(bufor[0])) {
            printf("This is not a text file. \n");
            exit(0);
        }

        i++;
    }

    printf("This is txt file.\n");

    if (close(fd) == -1) {
        perror("Error: ");
        exit(1);
    }

    exit(0);
}
