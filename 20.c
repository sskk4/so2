#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
gcc 20.c -o 20

9.4
Napisz program zmieniający kolejność znaków w każdej linii pliku o nazwie podanej jako parametr.
*/

void odwroc(const char *fileName) {
     FILE *file;
    char line[1024];

    file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Błąd otwarcia pliku");
        exit(EXIT_FAILURE);
    }

    char outputFileName[1036];
    snprintf(outputFileName, sizeof(outputFileName), "odwrocony_%s", fileName);
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Błąd otwarcia pliku docelowego");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        int length = strlen(line);
        for (int i = length - 1; i >= 0; i--) {
            fputc(line[i], outputFile);
        }
    }

    fclose(file);
    fclose(outputFile);

    printf("Zawartość pliku została pomyślnie odwrócona.\n");
}

int main(int argc, char* argv[]) {
    printf("hello.c\n\n");
    
    if (argc != 2) {
        fprintf(stderr, "Uzycie: %s <plik_wejsciowy>\n", argv[0]);
        exit(1);
    }

    odwroc(argv[1]);

    return 0;
}

