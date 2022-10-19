#include <stdio.h>

int main()
{

    int n, before = 0, now = 1, next = 0;

    scanf("%i", &n);

    for (int i = 1; i < n; i++)
    {

        if (i % 2 == 1)
        {
            printf("%i ",next);
            next = before + now;
            before = next;
        }
        else if (i == 2)
        {
            printf("%i ",next);
        }
        else if (i % 2 == 0)
        {
            printf("%i ",next);
            next = before + now;
            now = next;
        }
    }
    printf("%d\n",next);


    return 0;
}
