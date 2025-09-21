#include <stdio.h>

int main(){

    float salary,reajuste;
    scanf("%f", &salary);

    if (salary >= 0 && salary <= 400.00)
    {
        reajuste=salary*0.15;
        printf("Novo salario: %.2f\n",salary+reajuste);
        printf("Reajuste ganho: %.2f\n",reajuste);
        printf("Em percentual: 15 %%\n");
    }
    else if (salary >= 400.01 && salary <= 800.00)
    {
        reajuste=salary*0.12;
        printf("Novo salario: %.2f\n",salary+reajuste);
        printf("Reajuste ganho: %.2f\n",reajuste);
        printf("Em percentual: 12 %%\n");
    }
    else if (salary >= 800.01 && salary <= 1200.00)
    {
        reajuste=salary*0.10;
        printf("Novo salario: %.2f\n",salary+reajuste);
        printf("Reajuste ganho: %.2f\n",reajuste);
        printf("Em percentual: 10 %%\n");
    }else if (salary >= 1200.01 && salary <= 2000.00)
    {
        reajuste=salary*0.07;
        printf("Novo salario: %.2f\n",salary+reajuste);
        printf("Reajuste ganho: %.2f\n",reajuste);
        printf("Em percentual: 7 %%\n");
    }else{
         reajuste=salary*0.04;
        printf("Novo salario: %.2f\n",salary+reajuste);
        printf("Reajuste ganho: %.2f\n",reajuste);
        printf("Em percentual: 4 %%\n");
    }
    
    
    

    return 0;
}