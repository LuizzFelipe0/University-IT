#include <stdio.h>

int main()
{

    int x, n[10];

    scanf("%i", &x);

    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            n[0] = x;
            printf("N[%i] = %i\n", i, n[0]);
        }
        else
        {
            n[i] = n[i - 1] * 2;
            printf("N[%i] = %i\n", i, n[i]);
        }
    }

    return 0;
}