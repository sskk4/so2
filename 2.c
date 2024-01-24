#include <stdio.h>
#include <stdlib.h>

/* 
gcc 2.c -o 2 

1.2 
sprawdz czy strumien wejsciowy jest pusty
*/

int main(int argc, char* argv[]) {
    printf("empty.c\n\n");
    
    char checkEmpty;
    printf("for check -> ");

    checkEmpty = getchar();

    if(checkEmpty == '\n'){
        printf("is empty\n");
    } else {
        printf("is not empty\n");
    }

    return 0;
}

