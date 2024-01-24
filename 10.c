#define _XOPEN_SOURCE

#include <stdio.h>
#include <unistd.h>

/*
gcc -o 10 10.c -lcrypt

6.16
szyfrowanie haseł 
*/

char *crypt(const char *key, const char *salt);

// Programs using crypt should link to crypt.h using the compiler flag -lcrypt.

int main()
{
    char* password = "passw0rd";

    char* encrypted = crypt(password, "cd");

    printf("p: %s\n", password);
    printf("e: %s\n", encrypted);

    return 0;
}

