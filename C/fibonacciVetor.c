#include <stdio.h>

int main()
{
    int contador, n1, n2;
    unsigned long long int fib[61];

    fib[0] = 0;
    fib[1] = 1;

    for (contador = 2; contador < 61; contador++)
    {
        fib[contador] = fib[contador - 1] + fib[contador - 2];
    }

    scanf("%d", &n1);

    for (contador = 0; contador < n1; contador++)
    {
        scanf("%d", &n2);
        printf("Fib(%d) = %llu\n", n2, fib[n2]);
    }

    return 0;
}