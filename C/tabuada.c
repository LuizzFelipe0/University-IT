#include <stdio.h>

int main(){

    int x,result,i;
    scanf("%d", &x);

    for (i=1; i <= 10; i++)
    {
        result=(x*i);
        printf("%d x %d = %d\n",i,x,result);
    }
    

    return 0;
}