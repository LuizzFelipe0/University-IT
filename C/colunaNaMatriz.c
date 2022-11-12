#include <stdio.h>

int main()
{
    int n1, i, j;
    
    float Soma = 0.0, Media;
   
    float M[12][12];
    
    char YN;
  
    scanf("%i %c", &n1, &YN);
   
    for (i = 0; i < 12; i++)
    {
       
        for (j = 0; j < 12; j++)
        {
            scanf("%f", &M[i][j]);
            
            if (i < 12 && j == n1)
            {
                Soma = Soma + M[i][j];
            }
        }
    }
   
    if (YN == 'S')
    {
        printf("%.1f\n", Soma);
    }
  
    else if (YN == 'M')
    {
        Media = Soma / 12.0;
        
        printf("%.1f\n", Media);
    }
   
    return 0;
}