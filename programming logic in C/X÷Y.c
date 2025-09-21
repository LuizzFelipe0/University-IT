#include <stdio.h>

int main(){

    int x,y,n;
   
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d",&x,&y);
        
        if(y == 0){
            printf("divisao impossivel\n");
        }else{
            float division=(x*1.0)/(y);
            printf("%.1f\n",division);
        }
    }
    

    return 0;
}