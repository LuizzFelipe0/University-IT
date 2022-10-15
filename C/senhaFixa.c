#include <stdio.h>

int main(){

    int password, count,i;

    while (password != 2002)
    {
        scanf("%i", &password);
        if (password == 2002){
            printf("Acesso Permitido\n");
            return 0;

        }else{
            printf("Senha Invalida\n");
            
        }
    }
    
    return 0;
}