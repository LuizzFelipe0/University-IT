#include <stdio.h>
#include <unistd.h>

int main(){ // Sempre tem um processo. P1
    printf("SO2\n"); // SO2 Aparece uma vez

    // Criar um segundo processo
    int x = fork(); // P1 (x!=0) -> P2 (x=0)

    printf("TESTE\n"); // TESTE Aparece duas vezes

    int y = fork(); // P1(y!=0) -> P3 (y=0) e P2 (y!=0) -> P4 (y=0)

    printf("SEXTOU\n"); // SEXTOU Aparece 4 vezes.

    int z = fork(); // P1 -> P5 e P2 -> P6 e P3 -> P7 e P4 -> P8
}