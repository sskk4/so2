#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*
gcc 21.c -o 21

9.5
Napisz procedurę kopiowania ostatnich 10 znaków, słów i ostatnich 10 linii jednego pliku do innego.
*/

void copyChars(int fd) {

    int dest = creat("chars.txt", 0777);

    if (dest == -1) {
        perror("error");
        exit(1);
    }

    char buf[1];

    int i = 0;
    while (i < 10) {
        lseek(fd, -1*(i+1), SEEK_END);
        int readed = read(fd, buf, 1);
        write(dest, buf, readed);
        i++;
    }

    if (close(dest) == -1) {
        perror("Error: ");
        exit(1);
    }
}

void copyWords(int fd) {

    int dest = creat("words.txt", 0777);

    if (dest == -1) {
        perror("error: ");
        exit(1);
    }

    char buf[1];
    int i = 0;
    int temp = 0;
    while (i < 10) {
        lseek(fd, -1*(temp+1), SEEK_END);
        int readed = read(fd, buf, 1);
        write(dest, buf, readed);

        if (buf[0] == ' ' || buf[0] == '\n') i++;
        temp++;
    }

    if (close(dest) == -1) {
        perror("Error: ");
        exit(1);
    }
}

void copyLines(int fd) {
    int dest = creat("lines.txt", 0777);

    if(dest = -1) {
        perror("error: ");
        exit(1);
    }

    char buf[1];
    int i = 0;
    int temp = 0;
    while (i < 10) {
        lseek(fd, -1*(temp+1), SEEK_END);
        int readed = read(fd, buf, 1);
        write(dest, buf, readed);

        if (buf[0] == '\n') i++;
        temp++;
    }

    if (close(dest) == -1) {
        perror("Error: ");
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    int source_file = open("base.txt", O_RDONLY);

    if (source_file = -1) {
        perror("Error: ");
        exit(1);
    }

    copyChars(source_file);

    copyWords(source_file);

    copyLines(source_file);

    if (close(source_file) == -1) {
        perror("Error: ");
        exit(1);
    }

    exit(0);

}

