#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>

// Fazer um programa que utiliza dois processos, de forma que um processo escreve uma mensagem
// em um buffer compartilhado, e o outro lê esta mensagem e a escreve na tela.

int main(){
    char *message;

    // Criação da memória compartilhada
    int mem_id = shmget(IPC_PRIVATE, 50*sizeof(char), 0600);

    // Associar memória compartilhada
    message = (char*)shmat(mem_id, NULL, 0);

    int y = fork();

    if( y==0 ){ // P2
        printf("Digite uma mensagem: ");
        fgets(message, 50, stdin); // Lê do usuário para a memória compartilhada
        exit(0);

    } else {  // P1
        wait(NULL);

        // Imprime a mensagem que o filho escreveu
        printf("Mensagem = %s\n", message);
    }

    // Remove a variável compartilhada. A variável message não é mais compartilhada
    shmdt(message);
    // Apaga a memória compartilhada
    shmctl(mem_id, IPC_RMID, NULL);
}
