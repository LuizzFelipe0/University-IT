#include <stdio.h>

int lerNumero()
{
    int x;
    do
        scanf("%i", &x);
    while (x < 2 || x > 12);
    return x;
}

int fatorial(int n)
{
    int i, fat;

    fat = 1;
    for (i = n; i >= 1; i--)
        fat = fat * i;

    return fat;
}

int main()
{
    int numero;

    numero = lerNumero();

    printf("%i\n", fatorial(numero));

    return 0;
}