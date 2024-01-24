#include <stdio.h>
#include <stdlib.h>

/*
gcc 19.c -o 19

9.3
program kopiujący zawartość pliku o nazwie podanej jako pierwszy parametr, 
do pliku którego nazwa podana jest jako drugi parametr.
*/

void copyFile(const char *sourceFile, const char *destinationFile) {
    FILE *source, *destination;
    char ch;

    source = fopen(sourceFile, "r");
    if (source == NULL) {
        perror("Błąd otwarcia pliku źródłowego");
        exit(EXIT_FAILURE);
    }

    destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        perror("Błąd otwarcia pliku docelowego");
        fclose(source);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);
    printf("Zawartość pliku została pomyślnie skopiowana.\n");
}

int main(int argc, char *argv[]) {
    printf("hello.c\n\n");

    if (argc != 3) {
        fprintf(stderr, "Użycie: %s <plik_zrodlowy> <plik_docelowy>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    copyFile(argv[1], argv[2]);

    return 0;
}

