# **Processos - Guia Essencial de Bolso**



### **📋 CONCEITOS FUNDAMENTAIS**



#### O que é um Processo?



Um programa em execução, incluindo o código do programa e toda a informação do seu estado (memória, registradores, contador de programa, status de E/S) .


#### Quais são os estados de um Processo?


Execução (Running): Sendo processado pela CPU.


Pronto (Ready): Aguardando na fila para ser executado.


Espera (Wait/Blocked): Aguardando por algum evento externo ou recurso .

---

## **🌳 CRIAÇÃO DE PROCESSOS - ÁRVORE DE PROCESSOS**
Os processos pai criam processos filhos, que por sua vez podem criar outros processos, formando uma árvore de processos.



### Compartilhamento de recursos (três abordagens):


Pai e filhos compartilham todos os recursos.

Filhos compartilham apenas um subconjunto dos recursos do pai.

Pai e filho não compartilham recurso algum.


### Execução


Pai e filhos podem executar concorrentemente.

Ou o pai pode esperar até que os filhos terminem.



## **⎐  A CHAMADA FORK()**

    
    #include <unistd.h>
    pid_t fork(void);

### Valor de retorno do fork():

Zero no processo filho.

O PID (Process ID) do processo filho no processo pai.

Use o valor de retorno para identificar onde o código está sendo executado.

## **Exemplo Prático:**


    #include <stdio.h>
    #include <sys/types.h>
    #include <unistd.h>
    
    int main() {
        if (fork() == 0) {
            printf("Eu sou o filho\n");
        } else {
            printf("Eu sou o pai\n");
        }
    }


## **⏹️ TÉRMINO DE PROCESSO - EXIT()**


    #include <unistd.h>
    pid_t fork(void);


Processo executa instrução final e pede ao SO para terminá-lo com exit()

exit() realiza limpeza e retorna status de término

Retornar valor inteiro da função main() equivale a chamar exit() com mesmo valor

Processo que termina notifica pai passando exit status

Processo pai obtém status através de wait() ou waitpid()


## **⏳ A FUNÇÃO WAIT()**

    #include <sys/types.h>
    #include <sys/wait.h>
    pid_t wait(int *status);
    pid_t waitpid(pid_t pid, int *status, int options);

wait() e waitpid() usadas pelo pai para conhecer término do filho

### Comportamento do pai:
Bloqueia se todos filhos ainda executando

Retorna imediatamente com estado de término de um filho

Retorna imediatamente com erro

### Diferenças principais:
wait() bloqueia até qualquer processo filho terminar

waitpid() espera por processo filho específico (identificado por pid)

waitpid() tem opções para evitar bloqueio


## **☠️ PROCESSOS ZUMBI**


Ocorre quando processo filho termina antes do pai chamar wait()

Kernel mantém informações do processo terminado para pai recuperar status

Processo nesse estado chamado Zombie ou <defunct>

### O que acontece se pai termina antes do filho?

Processo init (PID 1) torna-se novo pai do processo órfão

init chama wait() quando filhos terminam, coletando status e evitando zombies permanentes

