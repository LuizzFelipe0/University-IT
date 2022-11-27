#include<stdio.h>
#include<string.h>

typedef struct
{
    int  codigo;
    char nome[50];
    char professor[50];
    int creditos,ano,semestre;
    double nota1,nota2;

} TDisciplina;


void ler(TDisciplina *d)
{
   char lixo;
   scanf("%i%c",&(*d).codigo,&lixo);
   scanf("%[^\n]%c",(*d).nome,&lixo);
   scanf("%[^\n]",(*d).professor);
   scanf("%i",&(*d).creditos);
   scanf("%i",&(*d).ano);
   scanf("%i",&(*d).semestre);
   scanf("%lf",&(*d).nota1);
   scanf("%lf",&(*d).nota2);
}

double media(TDisciplina d)
{
	return (d.nota1+2*d.nota2)/3;   
}

void mostrar(TDisciplina d)
{
  printf("Codigo    : %04i\n", d.codigo); 
  printf("Nome      : %s\n", d.nome); 
  printf("Professor : %s\n", d.professor);
  printf("Creditos  : %i\n", d.creditos); 
  printf("Ano       : %i\n", d.ano); 
  printf("Semestre  : %i\n", d.semestre); 
  printf("Nota1     : %.2lf\n", d.nota1); 
  printf("Nota2     : %.2lf\n", d.nota2); 
  printf("Media     : %.2lf\n", media(d)); 
}

int main()
{
   TDisciplina disc;

   ler(&disc);
   mostrar(disc); 

   return 0;
}



