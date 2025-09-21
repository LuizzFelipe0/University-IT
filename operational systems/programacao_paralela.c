#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t x, y = 1;  // Declara variáveis: x não inicializada, y = 1

    x = fork();       // PRIMEIRO fork(): cria um processo filho
                      // No pai: x > 0 (PID do filho)
                      // No filho: x = 0

    if (x == 0)       // Se é o processo filho do primeiro fork()
        y = fork();   // SEGUNDO fork(): cria outro processo (apenas no filho)
                      // No "filho do filho": y = 0
                      // No "filho original": y > 0 (PID do neto)

    fork();           // TERCEIRO fork(): executado por TODOS os processos existentes

    if (y == 0) {     // Se y == 0 (apenas processos específicos)
        fork();       // QUARTO fork(): executado apenas quando y == 0
        printf("programação paralela \n");
    }

    sleep(1);

    return 0;
}

/******************************************************************************
P0 (inicial, y=1)
├── P1 (filho de P0, x=0, y=PID_de_P2)
│   ├── P2 (filho de P1, y=0) ← Neto de P0
│   │   ├── P5 (filho de P2 pelo 3º fork)
│   │   │   └── P7 (filho de P5 pelo 4º fork)
│   │   └── P6 (filho de P2 pelo 4º fork)
│   └── P4 (filho de P1 pelo 3º fork)
└── P3 (filho de P0 pelo 3º fork)


Cronologia da criação dos processos:
Processo P0 (inicial) - y = 1

    Executa x = fork() → cria P1

        P0: x > 0 (não executa y = fork())

        P1: x = 0 (executa y = fork() → cria P2)

        P1: y > 0 (PID de P2)

Processo P2 (criado por P1) - y = 0

    Herda y = 0 do fork()

Terceiro fork() (executado por todos):

    P0 cria P3

    P1 cria P4

    P2 cria P5

Quarto fork() (apenas processos com y == 0):

    P2 (y=0) cria P6

    P5 (herdou y=0 de P2) cria P7

Quantidade de processos:
Total de processos criados: 8 processos

Processo inicial: 1 (P0)

    Fork 1: +1 (P1) → Total: 2

    Fork 2: +1 (P2) → Total: 3

    Fork 3: +3 (P3, P4, P5) → Total: 6

    Fork 4: +2 (P6, P7) → Total: 8

****/