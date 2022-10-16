#include <stdio.h>

int main()
{
    float n1,n3=0,n4=0;
    
    while(2){
       
        if(n4 == 2)
        break;
       
        scanf("%f", &n1);
       
        if(n1 >= 0 && n1 <= 10) {
            n4++;
            n3+=n1;
        }
       
        else
        printf("nota invalida\n");
    }
  
    float  media = n3/2;
  
    printf("media = %.2lf\n", media);
   
    return 0;
}