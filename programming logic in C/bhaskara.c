#include <stdio.h>
#include <math.h>

int main(){

    double A,B,C,Delta,r1,r2;

    scanf("%lf %lf %lf", &A, &B, &C);
    Delta = (pow(B, 2)) - (4 * A) * C;

    if (Delta < 0 || A == 0){
    printf("Impossivel calcular\n");
    }
    
    else{
     r1 = (B * -1 + (sqrt(Delta))) / (2 * A);
     r2 = (B * -1 - (sqrt(Delta))) / (2 * A);
     printf("R1 = %.5lf\n", r1);
     printf("R2 = %.5lf\n", r2);
}
   
    return 0;
}