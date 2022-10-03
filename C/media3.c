#include <stdio.h>

int main(){

    double n1, n2, n3, n4, nRec, media, mediaRec;

    scanf("%lf", &n1);
    scanf("%lf", &n2);
    scanf("%lf", &n3);
    scanf("%lf", &n4);

    media = (n1 * 0.2 + n2 * 0.3) + (n3 * 0.4 + n4 * 0.1);

    printf("Media: %.1lf\n", media);

    if (media >= 7)
    {
        printf("Aluno aprovado.\n");
    }
    else if (media < 5)
    {
        printf("Aluno reprovado.\n");
    }
    else if (media >= 5 && media < 7)
    {
        printf("Aluno em exame.\n");
        scanf("%lf", &nRec);
        mediaRec = (nRec + media) / 2;
        
        if (mediaRec < 5)
        {
            printf("Aluno reprovado.\n");
        }
        else
        {
            printf("Aluno aprovado.\n");
        }
        printf("Media Final: %.1lf\n", mediaRec);
    }

    return 0;
}