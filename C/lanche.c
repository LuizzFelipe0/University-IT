#include <stdio.h>

int main(){

    int n1,qtd;
    double price,total;
   
    scanf("%d %d",&n1,&qtd);
     if (n1==1) {
        price=4;
     }else if (n1==2){
        price=4.5;
     }else if (n1==3){
        price=5;
     }else if (n1==4) {
        price=2;
     }else if (n1==5) {
        price=1.5;
     }
     total=price*qtd;
     printf("Total: R$ %.2lf\n",total);
     
    return 0;
}