#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#define MAX 512

int main (int argc, char* argv[]){
	
	int desc;
	int lbajt;
	
	if (argc != 2){
		fprintf(stderr, "za malo argumenetow\n");
		exit(1);
	}

	desc = open(argv[1], O_RDWR);
	if (desc == -1){
		perror("Blad otwarcia pliku");
		exit(1);
	} 
	

	char buf[MAX];
	int i=1;

	while((lbajt = read(desc, buf, MAX)) > 0){
		if (write(desc, buf, lbajt) == -1){
			 perror("Blad zapisu pliku docelowego");
			exit(1);
		}
 	} 
	
	if (lbajt == -1){
		perror("Blad odczytu pliku zrodlowego");
		exit(1);
	}
	
	if (close(desc) == -1){
		perror("blad zamkniecia");
		exit(1);
	}
	
	exit(0);
}
