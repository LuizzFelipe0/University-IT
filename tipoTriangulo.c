#include <stdio.h>
#include <math.h>

int main()
{

    double A, B, C;

    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);

    if (A >= B + C){
        printf("NAO FORMA TRIANGULO");
    }
    else if ((pow(A, 2.0)) == (pow(B, 2.0)) + (pow(C, 2.0))){
            printf("TRIANGULO RETANGULO");
        }
    if ((pow(A, 2.0)) > (pow(B, 2.0)) + (pow(C, 2.0))){
            printf("TRIANGULO OBTUSANGULO");
        }
    if ((pow(A, 2.0)) < (pow(B, 2.0)) + (pow(C, 2.0))) {
            printf("TRIANGULO ACUTANGULO");
        }
    if (A == B && B == C){
        printf("TRIANGULO EQUILATERO");
    }
    else if (A == B || A == C || B == C){
        printf("TRIANGULO ISOSCELES");
    }

    return 0;
}