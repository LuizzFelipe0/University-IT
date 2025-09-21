#include <stdio.h>
int main()
{
     int X, Y;
    
     while (X != 0 || Y != 0)
     {
          scanf("%d%d", &X, &Y);
          
          if (X == 0 || Y == 0)
               break;
          else if (X > 0 && Y > 0)
               printf("primeiro\n");
          else if (X > 0 && Y < 0)
               printf("quarto\n");
          else if (X < 0 && Y < 0)
               printf("terceiro\n");
          else if (X < 0 && Y > 0)
               printf("segundo\n");
     }
    
     return 0;
}

/*#include <stdio.h>   VERSÃO EM FOR

int main(){

    int i,x,y,count;

    for (i = 0; i < count; i++)
    {
        scanf("%i %i", &x, &y);

        if (x > 0 && y > 0)
        {
             printf("primeiro\n");

        }else if (x < 0 && y > 0)
        {
             printf("segundo\n");

        }else if (x < 0 && y < 0)
        {
             printf("terceiro\n");

        }else if (x > 0 && y < 0)
        {
             printf("quarto\n");
        }else if (x == 0 || y == 0 )
        {
            return 0;
        }

    }

    return 0;
}
*/