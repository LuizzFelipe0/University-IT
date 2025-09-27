#include <stdio.h>
// Biblioteca para criação/uso de threads em C/Linux. Posix thread. Padrão UNIX.
#include <pthread.h>
#include <unistd.h>


void *imprime_mensagem(){
    // função 1
    // função 2
    // pthread_create(....);
    printf("THREAD CRIADA\n");
    sleep(1);
    // Thread termina/finalizada quando termina a função
}

int main(){ // Thread principal
    // Tipo da variável: pthread_t
    pthread_t thread_id1, thread_id2, thread_id3;

    // Criando uma nova thread
    // Thread_id: será preenchido com o id da thread criada.
    // 2º parâmetro: Atributos de sincronização: NULL - valores padrão para cada atributo
    // Informar a função que a thread criada irá executar. Ela não executa NADA na main.
    pthread_create(&thread_id1, NULL, imprime_mensagem, NULL);
    pthread_create(&thread_id2, NULL, imprime_mensagem, NULL);
    pthread_create(&thread_id3, NULL, imprime_mensagem, NULL);

    // Espera pelo término de uma thread;
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);

    printf("SO2\n");
}