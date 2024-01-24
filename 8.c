#include <stdio.h>
#include <stdlib.h>

/*
gcc 8.c -o 8

5.1.3 
files.c
Funkcja copy kopiuje pliki analogicznie do komendy cp.

*/

void copy(const char *addr1, const char *addr2) {
    FILE *sourceFile = fopen(addr1, "r");
    FILE *destinationFile = fopen(addr2, "w");

    if (sourceFile == NULL || destinationFile == NULL) {
        perror("Błąd otwarcia pliku");
        return EXIT_FAILURE;
    }

    int c;
    while ((c = fgetc(sourceFile)) != EOF) {
        fputc(c, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);
}

int main(int argc, char* argv[]) {
    printf("files.c\n\n");
    
    const char *sourceFileName = "file.txt";
    const char *destinationFileName = "file2.txt";

     copy(sourceFileName, destinationFileName);
    printf("\nPlik %s został skopiowany do %s.\n", sourceFileName, destinationFileName);

    return 0;
}

