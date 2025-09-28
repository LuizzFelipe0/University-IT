#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
// Shared memory: biblioteca que contém as funções de criação/uso da memória compartilhada
#include <sys/shm.h>

// Faça um programa que realize a soma dos valores de um vetor de tamanho 10
// usando dois processos. Um processo irá somar uma parte do vetor e outro processo
// irá somar a outra parte do vetor.

int main(){
    int v[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int *soma;

    // Criação da memória compartilhada
    // Key: Define a chave de acesso a memória compartilhada
    // Key: pode ser strtok("adm123") ou IPC_PRIVATE que define automaticamente
    // os processos filhos com acesso a memória compartilhada
    // Size: Tamanho da memória em bytes. sizeof: função que retorna o
    // tamanho em bytes que um determinado tipo ocupa na memória RAM.
    // Flag: define a permissão. Leitura e escrita
    // shmget(IPC_PRIVATE, sizeof(int), SHM_R | SHM_W);
    // Retorna o id da memória criada.
    int mem_id = shmget(IPC_PRIVATE, sizeof(int), 0600);

    // Função que torna uma variável "não compartilhada" em variável compartilhada.
    // 1º parâmetro: Id da memória comp. onde a variável será compartilhada
    // 2º parâmetro: especifica o endereço em que a variável será alocada.
    // Valor 0 obtém o primeiro endereço disponível.
    // Flag: define a permissão. Leitura e escrita. Valor 0 "herda" o que
    // foi definido na criação memória.
    // Compartilhando a variável soma
    soma = shmat(mem_id, 0, 0);
    //msg = shmat(mem_id, 0, 0);
    *soma = 0;

    int y = fork();

    if( y==0 ){ // P2
        for(int i = 0; i < 5; i++)
            *soma = *soma + v[i];
        exit(0);
    } else {  // P1
        for(int i = 5; i < 10; i++)
            *soma = *soma + v[i];
        wait(NULL);
    }

    printf("Soma = %d\n", *soma);

    // Remove a variável compartilhada. A variável soma não é mais compartilhada
    shmdt(soma);
    // Apaga a memória compartilhada
    shmctl(mem_id, IPC_RMID, NULL);
}
