#include <stdio.h>
#include <regex.h>

/*
gcc 16.c -o 16

8.1
program regexp ilustrujący wyrażenia regularne POSIX’a.
*/

int main(int argc, char* argv[]) {
    printf("regexp.c\n\n");
    
    regex_t regex;
    int result;
    char input[100];

    result = regcomp(&regex, "[0-9]", REG_EXTENDED);

    if (result != 0) {
        printf("blad kompilacji wyrazenia regularnego..\n");
        return 1;
    }

    printf("podaj string -> ");
    scanf("%s", input);

    result = regexec(&regex, input, 0, NULL, 0);

    if (result == 0) {
        printf("Ciag znakow pasuje\n");
    }   else if (result == REG_NOMATCH) {
        printf("Ciag znakow nie pasuje\n");
    }   else {
        printf("Blad porownania z wyrazeniem regularnym\n");
    }

    regfree(&regex);

    return 0;
}

