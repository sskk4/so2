#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
gcc 7.c -o 7

3.2.2
String.c
Funkcja identity zwracająca imię i nazwisko oddzielone spacją.
*/

char *identity(const char *name, const char *surname) {
    int length = strlen(name) + strlen(surname) + 2;
    char *buffer = (char *)malloc(length);
    snprintf(buffer, length, "%s %s",name, surname);
    return buffer;
}

/*
3.2.3
Funkcja login tworząca login użytkownika na podstawie pierwszej litery imienia i całego nazwiska.
 (Linux - max 32 znaki)
*/

char *login(const char *name, const char *surname) {
    int loginLength = strlen(surname) + 2;
    char *buffer = malloc(loginLength);
    snprintf(buffer, 32,"%c%s", name[0], surname);
    return buffer;
}

int main(int argc, char* argv[]) {
    printf("Strings.c\n\n");
    
    char *name = "John";
    char *surname = "Amerykan";
    
    char *id = identity(name, surname);
    printf("Identity: %s\n", id);
    free(id);

    char *userLogin = login(name, surname);
    printf("Login: %s\n", userLogin);
    free(userLogin);
    
    return 0;

}
