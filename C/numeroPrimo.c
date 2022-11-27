#include <stdio.h>

int main()
{
    int number, divisor, EhPrimo;

    divisor = 2;
    EhPrimo = 1;

    scanf("%d", &number);

    if (number <= 1)
        EhPrimo = 0;

    while (EhPrimo == 1 && divisor <= number / 2)
    {
        if (number % divisor == 0)
            EhPrimo = 0;
        divisor = divisor + 1;
    }

    if (EhPrimo == 1)
        printf("%d eh primo\n",number);
    else
        printf("%d nao eh primo\n",number);
    return 0;
}