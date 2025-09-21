#include <stdio.h>

int main(){

    int fatorial=1, N;
    scanf("%d",&N);

    for (int i = 1; i <= N; i++)
    {
       fatorial *= i;
    }
    printf("%d\n",fatorial);

    return 0;
}