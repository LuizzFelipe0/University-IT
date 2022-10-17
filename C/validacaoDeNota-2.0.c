#include <stdio.h>

int main()
{
    double n1, soma, contador, novoCalculo;

    while (1)
    {
        if (contador == 2)
            break;

        scanf("%lf", &n1);

        if (n1 >= 0 && n1 <= 10)
        {
            contador++;
            soma += n1;
        }
        else
            printf("nota invalida\n");
    }
    double media = soma / 2;

    printf("media = %.2lf\n", media);

    while (1)
    {
        printf("novo calculo (1-sim 2-nao)\n");

        scanf("%lf", &novoCalculo);

        if (novoCalculo == 2)
            break;

        if (novoCalculo != 1 && novoCalculo != 2)
            continue;

        if (novoCalculo == 1)
        {
            double n1, soma = 0, contador = 0, novoCalculo;

            while (1)
            {
                if (contador == 2)
                    break;
                scanf("%lf", &n1);
                if (n1 >= 0 && n1 <= 10)
                {
                    contador++;
                    soma += n1;
                }
                else
                    printf("nota invalida\n");
            }
            float media = soma / 2;

            printf("media = %.2lf\n", media);
        }
    }
    return 0;
}