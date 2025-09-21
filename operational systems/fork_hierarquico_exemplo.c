#include <stdio.h>
#include <unistd.h>

int main(){ // Sempre tem um processo. P1
    printf("SO2\n"); // Aparece uma vez

    // Criar um segundo processo
    int x = fork(); // P1 (x != 0) -> P2 (x = 0)

    if(x != 0){ // P2 = As funções executadas pelo processo P2
        int y = fork();
    } else { // P1 = As funções executadas pelo processo P1

    }
}