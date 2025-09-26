#include <stdio.h>
#include <unistd.h>

int main() {
    int x = fork();

    if (x > 0) {
        printf("Eu sou o pai! PID do meu filho é: %d\n", x);
    }

    if (x == 0) {
        printf("Eu sou o filho!\n");
    }
}