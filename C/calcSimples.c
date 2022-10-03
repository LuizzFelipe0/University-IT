#include <stdio.h>
 
int main() {
 
    int codP1,numP1,codP2,numP2;
    double valorU1,valorU2,calc1,calc2,total;
    
    scanf("%d",&codP1);
    scanf("%d",&numP1);
    scanf("%lf",&valorU1);
    calc1=numP1*valorU1;
    scanf("%d",&codP2);
    scanf("%d",&numP2);
    scanf("%lf",&valorU2);
   
    calc2=numP2*valorU2;
    total=calc1+calc2;
        
    printf("VALOR A PAGAR: R$ %.2lf\n", total);

    return 0;
}