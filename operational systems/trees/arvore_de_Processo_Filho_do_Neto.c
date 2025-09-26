/******************************************************************************

– Implemente um programa que:  

a) Gere a árvore de processos abaixo ao ser executado.  

             PAI 
            / | \
           F1 F2 F3
          /
         N1
        /
       NN2

b) Cada processo deve imprimir o seu ID de forma separada. 

*******************************************************************************/

#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 

int main()
{
    pid_t pid1, pid2, pid3, pid4,pid5;
    
    pid1 = fork();
    
    if (pid1 < 0) {
        printf("Erro ao criar o processo filho pid1");
        return 1;
    }
    else if (pid1 == 0) {
        printf("Processo F1 - PID: %d\n", getpid()); 
            
            pid4 = fork();
        
            if (pid4 < 0) {
                printf("Erro ao criar o processo filho pid4");
                return 1;
            }
            else if (pid4== 0) {
                printf("Processo NETO F4 - PID: %d\n", getpid()); 
                
                pid5 = fork();
                
                if (pid5 < 0) {
                    printf("Erro ao criar o processo filho do neto pid5");
                    return 1;
                }
                else if (pid5 == 0) {
                    printf("Processo FILHO DO NETO F5 - PID: %d\n", getpid()); 
                    return 0; 
                }
                
                return 0; 
    }   
        return 0; 
    }   
    
    pid2 = fork();
    
    if (pid2 < 0) {
        printf("Erro ao criar o processo filho pid2");
        return 1;
    }
    else if (pid2 == 0) {
        printf("Processo F2 - PID: %d\n", getpid()); 
        return 0; 
    }   
    
    pid3 = fork();
    
    if (pid3 < 0) {
        printf("Erro ao criar o processo filho pid3");
        return 1;
    }
    else if (pid3 == 0) {
        printf("Processo F3 - PID: %d\n", getpid()); 
        return 0; 
    }   
    
    printf("Processo PAI: %d\n", getpid()); 
    
    sleep(2);
    
    return 0;
}