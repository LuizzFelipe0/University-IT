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

typedef struct
{
   TDisciplina vet[100];
   int         qtd;
} THistorico;


void ler(TDisciplina *d)
{
   scanf("%i%*c",&(*d).codigo);
   scanf("%[^\n]%*c",(*d).nome);
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


void inicializar(THistorico *h)
{
    (*h).qtd = 0;
}

void inserir(THistorico *h, TDisciplina d)
{
   (*h).vet[(*h).qtd] = d;
   (*h).qtd++;
}

void listar(THistorico h)
{
   int i;
   TDisciplina d;
   printf("%4s %-50s %4s %4s/%s %s\n", 
          "Cod.", "Nome","Cred", "Ano", "S", "Media");
   for(i=0;i<h.qtd;i++)
   {
      d = h.vet[i];
      printf("%04i %-50s %4i %4i/%i %05.2lf\n", 
             d.codigo, d.nome, d.creditos, d.ano, 
             d.semestre, media(d));
   }
}

void listarPorAnoSemestre(THistorico h, int Ano, int Semestre)
{
   int i;
   TDisciplina d;
   printf("%4s %-50s %4s %4s/%s %s\n", 
          "Cod.", "Nome","Cred", "Ano", "S", "Media");
   for(i=0;i<h.qtd;i++)
   {
      d = h.vet[i];
      if (d.ano == Ano && d.semestre==Semestre)
      	 printf("%04i %-50s %4i %4i/%i %05.2lf\n", 
             d.codigo, d.nome, d.creditos, d.ano, 
             d.semestre, media(d));
   }
}

void listarPorParteNomeProf(THistorico h, char parte[])
{
   int i;
   TDisciplina d;
   printf("%4s %-50s %4s %4s/%s %s\n", 
          "Cod.", "Nome","Cred", "Ano", "S", "Media");
   for(i=0;i<h.qtd;i++)
   {
      d = h.vet[i];
      if (strstr(d.nome,parte)!=NULL || strstr(d.professor,parte)!=NULL)
      	 printf("%04i %-50s %4i %4i/%i %05.2lf\n", 
             d.codigo, d.nome, d.creditos, d.ano, 
             d.semestre, media(d));
   }
}

double cr(THistorico h)
{
   int i,creditos;
   TDisciplina d;
   double soma;
   soma = creditos = 0;
   for(i=0;i<h.qtd;i++)
   {
      d = h.vet[i];
      creditos = creditos + d.creditos;
      soma = soma + d.creditos*media(d);
   }
   return creditos==0 ? 0 : soma/creditos;
}

void mostrarHistorico(THistorico h)
{
    listar(h);
    printf("Coeficiente de Rendimento                                           %05.2lf\n",cr(h));
}

int obterIndice(THistorico h, int codigo)
{
    int i,achou;
    i=0; //primeiro elemento esta na posicao zero
    achou = 0; //falso
    while (!achou && i<h.qtd)
      if (h.vet[i].codigo == codigo)
         achou = 1;//verdadeiro
      else
         i++;//passa para a proxima disciplina
    return achou ? i : -1;
}

int existe(THistorico h, int codigo)
{
   return obterIndice(h,codigo)!=-1;
}
 
void remover(THistorico *h, int codigo)
{
    int pos = obterIndice(*h,codigo);
    int i;
    if (pos>-1)
    {
       for(i=pos+1;i<(*h).qtd;i++)
          (*h).vet[i-1] = (*h).vet[i];
       (*h).qtd--;   
    }
} 

void alterar(THistorico *h, int codigo, TDisciplina disc)
{
    int pos = obterIndice(*h,codigo);
    if (pos>-1)
			(*h).vet[pos] = disc;    	
} 



int menu()
{
   int opc;
   do{
      printf("1 - inserir nova disciplina\n");
      printf("2 - remover disciplina pelo codigo\n");
      printf("3 - alterar disciplina pelo codigo\n");
      printf("4 - listar todas as disciplinas\n");
      printf("5 - listar disciplinas de um ano/semestre\n");
      printf("6 - listar disciplinas pelo nome/professor\n");
      printf("7 - Historico\n");
      printf("8 - sair\n");
   	 printf("Entre com a sua opcao:\n");
      scanf("%i%*c",&opc);
   }while (opc<1 || opc>8);
   return opc;
}

void esperarOk()
{
   char linha[1000];
   do{
     scanf("%s",linha);
   }while (strcmp(linha,"Ok")!=0); 
}

int main()
{
   TDisciplina ficha;
   THistorico hist;
   int acabou = 0;
   int codigo,ano,sem;
   char str[50];
   inicializar(&hist);
   while (!acabou)
     switch( menu() )
   	{
     	case 1:  
          ler(&ficha);
          inserir(&hist, ficha);
          printf("Disciplina inserida com sucesso!\n");
          break;
     	case 2:
          scanf("%i",&codigo);
          if (existe(hist, codigo))
          {
              remover(&hist,codigo);
              printf("Disciplina removida com sucesso!\n");
          }
          else
             printf("Disciplina nao encontrada!\n");
          break;
     	case 3:
          scanf("%i",&codigo);
          if (existe(hist, codigo))
          {
              ler(&ficha);
              alterar(&hist,codigo, ficha);
              printf("Disciplina alterada com sucesso!\n");
          }
          else
             printf("Disciplina nao encontrada!\n");
          break;
     	case 4:
          listar(hist);
          esperarOk(); 
          break;
     	case 5:
          scanf("%i%i",&ano,&sem);
          listarPorAnoSemestre(hist,ano,sem);
          esperarOk(); 
          break;
     	case 6:
          scanf("%[^\n]",str);
          listarPorParteNomeProf(hist, str);
          esperarOk(); 
          break;
     	case 7:
          mostrarHistorico(hist);
          esperarOk(); 
          break;
     	case 8:
          acabou = 1;
          break;
   	}
   printf("Obrigado por utilizar o programa de cadastro, volte sempre!\n");
   return 0;
}



