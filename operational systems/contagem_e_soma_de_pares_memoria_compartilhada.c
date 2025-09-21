#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>

// Fazer um programa em para contabilizar quantos elementos de um vetor de 1000 posições são
// números pares usando 4 processos. Cada processo irá verificar uma parte do vetor. Cada processo irá passar
// seu resultado ao processo 0, que irá somá-lo ao resultado parcial gerado pelo 0.

int main() {
    int elementos[1000];
    int total_pares = 0;

    // Inicializa vetor
    for (int i = 0; i < 1000; i++) {
        elementos[i] = i + 1;
    }

    // Criar memória compartilhada para os resultados
    int shm_id = shmget(IPC_PRIVATE, 4 * sizeof(int), 0600 | IPC_CREAT);

    // Mapea memória compartilhada
    int *resultados = (int *)shmat(shm_id, NULL, 0);

    // Inicializa resultados
    for (int i = 0; i < 4; i++) {
        resultados[i] = 0;
    }

    // Cria 4 processos
    for (int i = 0; i < 4; i++) {
        pid_t pid = fork();

        if (pid == 0) { // Processo filho
            int inicio = i * 250;
            int fim = inicio + 250;
            int contador = 0;

            // Conta pares na sua parte do vetor
            for (int j = inicio; j < fim; j++) {
                if (elementos[j] % 2 == 0) {
                    contador++;
                }
            }
            // Armazena resultado na memória compartilhada
            resultados[i] = contador;

            // Desmapea e sai
            shmdt(resultados);
            exit(0);
        }
    }

    // Processo pai espera por todos os filhos
    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    // Soma todos os resultados
    for (int i = 0; i < 4; i++) {
        total_pares += resultados[i];
        printf("Processo %d: %d números pares\n", i, resultados[i]);
    }

    printf("Total de números pares: %d\n", total_pares);

    // Limpa
    shmdt(resultados);
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}