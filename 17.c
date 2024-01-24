#include <stdio.h>
#include <string.h>

/*
gcc 17.c -o 17

8.2
3
Funkcja wariacje2 wylicza metodą brutalnej siły liczbę ciągów 2-elementowych, 
jakie można utworzyć z wartości określonych wyrażeniem regularnym [a-zA-Z0-9./] *
*/

int sprawdz(char c) {
    return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c >= '.' || c <= '/');
}

void wariacje2() {
    char znaki[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";
    int count = 0;

    for (int i = 0; i < strlen(znaki); i++) {
        for (int j = 0; j < strlen(znaki); j++) {
            if(sprawdz(znaki[i]) && sprawdz(znaki[j])) {
                printf("%c%c\n", znaki[i], znaki[j]);
                count++;
            }
        }
    }
}


int main(int argc, char* argv[]) {
    printf("wariacje2.c\n\n");
    wariacje2();
    return 0;
}

