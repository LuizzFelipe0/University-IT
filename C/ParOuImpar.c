#include <stdio.h>

int main(){

    int n,count,i;
    scanf("%i",&count);

    for (i = 0; i < count; i++){
        
        scanf("%i",&n);
       
        if (n % 2 == 0 && n > 0){
            printf("EVEN POSITIVE\n");

        }else if (n % 2 == 0 && n < 0){
            printf("EVEN NEGATIVE\n");

        }else if (n % 2 != 0 && n > 0){
			printf("ODD POSITIVE\n");

        }else if (n % 2 != 0 && n < 0){
			printf("ODD NEGATIVE\n");
            
        }else if(n == 0){
            printf("NULL\n");
        }
        
    }

    return 0;
}
