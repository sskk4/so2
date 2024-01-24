#include <stdio.h>
#include <stdlib.h>

/*
gcc 11.c -o 11

6.20
program delusers usuwający użytkowników podanych na liście w pliku.
*/

#define MAX_USERNAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 100
#define MAX_FILENAME_LENGTH 100

void removeUser(const char *username) {
    char command[MAX_USERNAME_LENGTH + 15];
    snprintf(command, sizeof(command), "sudo userdel %s", username);

    int status = system(command);

    if (status == 0) {  
        printf("Usunięto użytkownika: %s\n", username);
    } else {
        printf("Błąd usuwania użytkownika: %s\n", username);
    }
}

int main(int argc, char* argv[]) {
    printf("removeUser.c\n\n");
    
    const char *filename = "file.txt";

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Błąd otwarcia pliku");
        return EXIT_FAILURE;
    }

    char line[MAX_USERNAME_LENGTH + MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 3];

     while (fgets(line, sizeof(line), fp) != NULL) {
        char *token = strtok(line, ";");  
        if (token != NULL) {
            while (isspace(*token)) {
                ++token;
            }

            size_t len = strlen(token);
            if (len > 0 && token[len - 1] == '\n') {
                token[len - 1] = '\0';
            }

            removeUser(token);
        }
    }

    fclose(fp);

    return EXIT_SUCCESS;

}

