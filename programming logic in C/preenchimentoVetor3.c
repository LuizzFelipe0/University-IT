#include <stdio.h>

int main()
{

    double x, n[100];

    scanf("%lf", &x);

    n[0] = x;

    for (int i = 1; i <= 100; i++)
    {
        if (i == 1)
        {
            n[i] = x / 2.0;
        }
        else
        {
            n[i] = n[i-1] / 2.0;
        }
    }
    for (int k = 0; k < 100; k++)
    {
        printf("N[%i] = %.4f\n", k, n[k]);
    }

    return 0;
}