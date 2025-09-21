#include <stdio.h>

typedef struct
{
    int anos;
    char nome, estadoCivil;
    double salarioI, percentualAumento;

} pessoa;

void contador(pessoa pe)
{
    int count;

    scanf(%d, &count);

    for (int i = 0; i < count; i++)
    {
        ler(&pe);
    }
}

void ler(pessoa *p)
{
    scanf("%[^\n]%*c", (*p).nome);
    scanf("%lf", &(*p).salarioI);
    scanf("%i", &(*p).anos);
    scanf("%i%*c", &(*p).estadoCivil);
}

void aumento(pessoa auau)
{
    double salarioAumento, salarioAumento5c;

    salarioAumento = (auau.salarioI * 0.08);
    salarioAumento5c = (auau.salarioI * 0.10);
}

int main()
{
    pessoa x;
    ler(&x);
}
