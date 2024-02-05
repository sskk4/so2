#include <stdio.h>
#include <stdlib.h>

int main() {
    // Wskaznik na plik
    FILE *file;

    // Otwarcie pliku do odczytu
    file = fopen("input.txt", "r");

    // Sprawdzenie, czy otwarcie pliku się udało
    if (file == NULL) {
        perror("Blad otwarcia pliku");
        exit(EXIT_FAILURE);
    }

    int number;
    int sum = 0;

    // Odczyt liczb z pliku i obliczenie sumy
    while (fscanf(file, "%d", &number) == 1) {
        sum += number;
    }

    // Zamknięcie pliku
    fclose(file);

    // Wyświetlenie sumy
    printf("Suma liczb z pliku: %d\n", sum);

    return 0;
}

