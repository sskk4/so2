#include <stdio.h>
#include <stdlib.h>

/*
gcc 3.c -o 3

1.3.3
fibo3.c

ciag fibonacciego metoda programowania dynamicznego 
z ramka dwuzebna 

odp do pytan
1. ile razy przesunac ramke aby wyznaczyc nty wyraz ciagu dla n>=2
odp. nalezy przesunac n-1 aby uzyskać nty wyraz

2.dokonaj analizy wywołania fibo3(4)
fibo3(4):
1: r0 = 1, r1 = 1, pom = 0
2: r0 = 1, r1 = 1, pom = 1
3: r0 = 1, r2 = 2, pom = 1
4: r0 = 2, r1 = 3, pom = 1
5: r0 = 3, r1 = 5, pom = 2
wynik: 5

3.narysuj graf obliczen dla fibo 3(4):
r0              1   1   1   2   3
r1              1   1   2   3   5
pom             0   1   1   1   2
przesuniecie    1   2   3   4   5

4. ktora jest szybsza fibo2(ramka trojzebna) czy fibo3
fibo3 jest szybsza poniewaz unika dynamicznego alokowania i zwalniania pamieci

5. cztery inne funkcje wyliczajace rekurencyjnie wartosc ciagu ibo
1. prosta rekurencja bez optymalizacji
2. rekurencja z pamiecia
3. rekurencja z pamiecia globalna
4. reukrencja z uzyciem operatora trojargumentowego
*/

int fibo3(int n) {
        if (n == 0 || n == 1) {
        return 1;
    }

        int r0 = 1;
        int r1 = 1;
        int pom = 0;

        for (int i = 2; i<=n; i++)
        {
            pom = r0;
            r0 = r1;
            r1 = r0 + pom;
        }

        return r1;
    }

int main(int argc, char* argv[]) {
    printf("fibo.c\n\n");
    
    int n = 0;

    printf("fibo3(%d) = %d\n", n, fibo3(n));

    return 0;

}

