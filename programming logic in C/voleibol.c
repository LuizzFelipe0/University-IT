#include <stdio.h>

int main()
{
    char Nome[10000];
    int number, S, B, A, S1, B1, A1;
    float SS = 0.00, SB = 0.00, SA = 0.00, SS1 = 0.00, SB1 = 0.00, SA1 = 0.00, RS, RB, RA;
   
    scanf("%d", &number);
   
    for (int i = 1; i <= number; i++)
    {
        scanf("%s", Nome);
        scanf("%i %i %i", &S, &B, &A);
        scanf("%i %i %i", &S1, &B1, &A1);
       
        SS += S;
        SB += B;
        SA += A;
        SS1 += S1;
        SB1 += B1;
        SA1 += A1;
   
    }
   
    RS = (SS1 / SS) * 100.00;
    RB = (SB1 / SB) * 100.00;
    RA = (SA1 / SA) * 100.00;
    
    printf("Pontos de Saque: %.2f %%.\n", RS);
   
    printf("Pontos de Bloqueio: %.2f %%.\n", RB);
   
    printf("Pontos de Ataque: %.2f %%.\n", RA);
    
    return 0;
}