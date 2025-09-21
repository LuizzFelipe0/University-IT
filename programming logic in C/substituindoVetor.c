#include <stdio.h>

int main()
{

    int n1, X[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%i", &n1);
      
        if (n1 <= 0)
        {
            X[i] = 1;
        }
        else
        {
            X[i] = n1;
        }
    }

    for (int j = 0; j < 10; j++)
    {
        printf("X[%i] = %i\n", j, X[j]);
    }
    return 0;
}
