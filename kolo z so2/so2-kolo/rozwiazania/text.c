#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#define MAX 512

int main (int argc, char* argv[]){
	
	int desc_cel, desc_zrod;
	int lbajt;
	
	if (argc != 3){
		fprintf(stderr, "za malo argumenetow\n");
		exit(1);
	}

	desc_zrod = open(argv[1], O_RDONLY);
	if (desc_zrod == -1){
		perror("Blad otwarcia pliku");
		exit(1);
	} 
	
	desc_cel = open(argv[2], O_WRONLY);
	if (desc_cel == -1){
		perror("Blad otwarcia pliku");
		exit(1);
	}
	
	char buf[MAX];
	int i=1;
	while((lbajt = read(desc_zrod, buf, MAX)) > 0){
		if (write(desc_cel, buf, lbajt) == -1){
			perror("Blad zapisu pliku docelowego");
			exit(1);
		}
 	} 
	
	if (lbajt == -1){
		perror("Blad odczytu pliku zrodlowego");
		exit(1);
	}
	
	if (close(desc_zrod) == -1 || close(desc_cel) == -1){
		perror("blad zamkniecia");
		exit(1);
	}
	
	exit(0);
}
