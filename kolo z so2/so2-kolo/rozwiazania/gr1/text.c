#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

/*
gcc text.c -o text

Napisz program text sprawdzajacy, czy plik o nazwie podanej
jako parametr jest plikiem tekstowym. 
Plik tekstowy zawiera znaki o kodach 0-127. 
Przyk³adowe sesje
Nie podales nazwy pliku
Plik ala.txt jest plikiem tekstowym
Plik ola.exe nie jest plikiem tekstowym
*/


int main(int argc, char* argv[]) {
    printf("text.c\n\n");
    
    if (argc != 2) {
    	fprintf(stderr, "Nie podales nazwy pliku. \n");
    	exit(1);
	}
	
	int fd = open(argv[1], O_RDONLY);
	
	if (fd == -1) {
		perror("Error: ");
		exit(1);
	}
	
	char bufor[1];
	int i = 1;
	
	while(read(fd, bufor, 1) > 0) {
		if(!isascii(bufor[0])) {
			printf("plik %s nie jest plikiem tekstowym", argv[1]);
			exit(0);
		}
	
	i++;
	}
    
    printf("Plik %s jest plikiem tekstowym", argv[1]);
    
    if (close(fd) == -1) {
    	perror("Error: ");
    	exit(1);
	}
    
    return 0;
}

