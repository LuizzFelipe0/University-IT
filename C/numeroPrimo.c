#include <stdio.h>

int main()
{

    int number, N, divisor, divisions;

    scanf("%i", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%i", &number);

        for (divisor = 1, divisions = 0; divisor <= number; divisor++)
        {
            if (number % divisor == 0)
            {
                divisions++;
            }
        }
        if (divisions == 2)
        {
            printf("%d eh primo\n", number);
        }
        else if (divisions > 2)
        {
            printf("%d nao eh primo\n", number);
        }
    }

    return 0;
}