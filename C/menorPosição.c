#include <stdio.h>

int main()
{

    int n1;

    scanf("%i", &n1);

    int X[n1];

    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &X[i]);
    }

    int menorValor = X[0];

    for (int i = 1; i < n1; i++)
    {
        if (X[i] < menorValor)
        {
            menorValor = X[i];
        }
    }

    int posicao;
    for (int i = 0; i < n1; i++)
    {
        if (menorValor == X[i])
        {
            posicao = i;
            break;
        }
    }
    printf("Menor valor: %d\n", menorValor);
    printf("Posicao: %d\n", posicao);
   
    return 0;
}