#include <stdio.h>
#include <stdlib.h>

/*
gcc 14.c -o 14

7.5
program version wypisujący wersję biblioteki libc na 3 różne sposoby dla systemu Linux i Windows. 
*/

#ifdef _WIN32
// Dla systemu Windows
#include <windows.h>

void printLibcVersion() {
    printf("Wersja libc dla systemu Windows: %s\n", _get_current_libc_version());
}

#elif __linux__
// Dla systemu Linux
#include <gnu/libc-version.h>

void printLibcVersion() {
    printf("Wersja libc dla systemu Linux: %s\n", gnu_get_libc_version());
}

#endif

int main() {
    printLibcVersion();
    return 0;
}

