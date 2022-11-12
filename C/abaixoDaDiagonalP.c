#include <stdio.h>

int main()
{

    int i, j;
   
    float Soma = 0.0, Matriz[12][12];
   
    char sm[2];
    
    scanf("%s", sm);

    for (i = 0; i <= 11; i++)
    {
        for (j = 0; j <= 11; j++)
        {
            scanf("%f", &Matriz[i][j]);

            if (j < i)
            {
                Soma += Matriz[i][j];
            }
        }
    }

    if (sm[0] == 'S')
    {
        printf("%.1f\n", Soma);
    }
    else
    {
        Soma = Soma / 66.0;
        printf("%.1f\n", Soma);
    }

    return 0;
}