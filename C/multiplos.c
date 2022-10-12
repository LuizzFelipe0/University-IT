#include <stdio.h>

int main()
{

    int M1, M2;
    scanf("%d %d", &M1, &M2);

    if (M1 >= M2)
    {
        if (M1 % M2 == 0)
        {
            printf("Sao Multiplos\n");
        }
        else
        {
            printf("Nao sao Multiplos\n");
        }
    }

    else if (M2 >= M1)
    {
        if (M2 % M1 == 0)
        {
            printf("Sao Multiplos\n");
        }
        else
        {
            printf("Nao sao Multiplos\n");
        }
    }

    return 0;
}