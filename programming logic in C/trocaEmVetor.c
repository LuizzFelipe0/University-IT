#include <stdio.h>

int main()
{
    int vetor[20];

    for (int i = 19; i >= 0; i--)
    {
        scanf("%i", &vetor[i]);
    }

    for (int j = 0; j < 20; j++)
    {
        printf("N[%i] = %i\n", j, vetor[j]);
    }

    return 0;
}