#include <stdio.h>
// Biblioteca para criação/uso de threads em C/Linux. Posix thread. Padrão UNIX.
#include <pthread.h>


void *imprime_mensagem(){
    // função 1
    // função 2
    // pthread_create(....);
    printf("THREAD CRIADA\n");
    while(1);
    // Thread termina/finalizada quando termina a função
}

int main(){ // Thread principal
    // Tipo da variável: pthread_t
    pthread_t thread_id;

    // Criando uma nova thread
    // Thread_id: será preenchido com o id da thread criada.
    // 2º parâmetro: Atributos de sincronização: NULL - valores padrão para cada atributo
    // Informar a função que a thread criada irá executar. Ela não executa NADA na main.
    pthread_create(&thread_id, NULL, imprime_mensagem, NULL);

    printf("SO2\n");
    while(1);
}