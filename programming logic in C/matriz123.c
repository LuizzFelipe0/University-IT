#include <stdio.h>

int main()
{

    unsigned short int size, line, column;

    while (scanf("%hd", &size) != EOF)
    {
        short M[size][size];

        for (line = 0; line < size; line++)
         
            for (column = 0; column < size; column++)
            {
               
                if (line == column)
                   
                    M[line][column] = 1;
               
                if (line == size - column - 1)
                   
                    M[line][column] = 2;
               
                if (line != column && line != size - column - 1)
                    
                    M[line][column] = 3;
            }

        for (line = 0; line < size; line++)
        {
            for (column = 0; column < size; column++)
               
                printf("%d", M[line][column]);

            printf("\n");
        }
    }

    return 0;
}