#include <stdio.h>

int main()
{

    double a, b, c, perimeter, area;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    perimeter = a + b + c;
    area = ((a + b) * c) / 2;

    if (a < b + c && b < a + c && c < a + b)
    {
        printf("Perimetro = %.1lf\n", perimeter);
    }
    else
    {
        printf("Area = %.1lf\n", area);
    }

    return 0;
}