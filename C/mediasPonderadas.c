#include <stdio.h>

int main(){

    int count;
    double p2,p3,p5,media;

    scanf("%i", &count);

    for (int i = 0; i < count; i++)
    {
        scanf("%lf %lf %lf", &p2, &p3, &p5);
        
        media=((p2*2)+(p3*3)+(p5*5))/10;

        printf("%.1lf\n", media);
    }
    

    return 0;
}