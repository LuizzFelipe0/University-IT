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

