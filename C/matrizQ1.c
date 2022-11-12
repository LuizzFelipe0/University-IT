#include <stdio.h>

int main()
{

    int N, x;

    scanf("%i", &N);

    while (N != 0)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                x = i;
                if (j < x)
                    x = j;
                if (N - i + 1 < x)
                    x = N - i + 1;
                if (N - j + 1 < x)
                    x = N - j + 1;

                printf("%3d", x);
                if (j < N)
                {
                    printf(" ");
                }
                else
                {
                    printf("\n");
                }
            }
        }
        printf("\n");
        scanf("%i", &N);
    }

    return 0;
}