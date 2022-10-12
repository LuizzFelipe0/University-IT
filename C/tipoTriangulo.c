#include <stdio.h>
#include <math.h>

int main()
{

    float A, B, C, x;

    scanf("%f", &A);
    scanf("%f", &B);
    scanf("%f", &C);

     if (A < B){ x = A; A = B; B = x; } 
     if (B < C){ x = B; B = C; C = x; } 
     if (A < B){ x = A; A = B; B = x; }
     if (A >= B + C){
        printf("NAO FORMA TRIANGULO\n");
    }
    else if ((pow(A, 2)) == (pow(B, 2)) + (pow(C, 2))){
            printf("TRIANGULO RETANGULO\n");
        }
    else if ((pow(A, 2)) > (pow(B, 2)) + (pow(C, 2))){
            printf("TRIANGULO OBTUSANGULO\n");
        }
   else if ((pow(A, 2)) < (pow(B, 2)) + (pow(C, 2))) {
            printf("TRIANGULO ACUTANGULO\n");
        }
    if (A == B && B == C){
        printf("TRIANGULO EQUILATERO\n");
    }
    else if (A == B || B == C){
        printf("TRIANGULO ISOSCELES\n");
    }

    return 0;
}