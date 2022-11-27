#include <stdio.h>

int somaDivisores(int n)
{
    int i, soma;
    soma = 0;
    for (i = 1; i < n; i++)
        if (n % i == 0)
            soma = soma + i;
    return soma;
}

int amigos(int a, int b)
{
    /*if (somaDivisores(a)==b && somaDivisores(b)==a)
      return 1;
    else
      return 0;
    */
    return somaDivisores(a) == b && somaDivisores(b) == a;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (amigos(a, b))
        printf("Os numeros %i e %i sao amigos\n", a, b);
    else
        printf("Os numeros %i e %i nao sao amigos\n", a, b);
    return 0;
}