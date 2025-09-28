# **Docker - Guia Essencial de Bolso**



### **📋 CONCEITOS FUNDAMENTAIS**



#### O que é Docker?



Docker é a ferramenta mais popular e um exemplo fundamental de conteinerização de aplicações. Ele é uma plataforma que simplifica a criação, o gerenciamento e a execução de contêineres.



Como funciona a conteinerização com o Docker?

---

**Isolamento**: Em vez de executar uma aplicação diretamente no sistema operacional, o Docker cria um "contêiner" para ela. Esse contêiner é um ambiente isolado que empacota o código da aplicação e todas as suas dependências, como bibliotecas, ferramentas de sistema e configurações.


**Portabilidade**: Como o contêiner inclui tudo o que a aplicação precisa para rodar, ele pode ser executado de forma consistente em qualquer ambiente que tenha o Docker Engine instalado, seja em um computador de desenvolvimento, em servidores de testes ou em produção. Isso elimina o problema clássico de "na minha máquina funciona".


**Eficiência**: Diferentemente das máquinas virtuais (VMs), que precisam de um sistema operacional completo, os contêineres Docker compartilham o kernel do sistema operacional do host. Isso os torna muito mais leves e rápidos para iniciar e executar.


**Padronização**: O Docker cria um padrão para empacotar e distribuir software, facilitando o gerenciamento da infraestrutura e a colaboração entre desenvolvedores e administradores de sistemas (DevOps). 



## **🐳 COMANDOS ESSENCIAIS DOCKER**



### Gerenciar Imagens



docker build -t minha-app .                    # Constrói imagem do Dockerfile

docker pull ubuntu:22.04                       # Baixa imagem do registry

docker images                                  # Lista imagens locais

docker rmi ubuntu:latest                       # Remove imagem local



### Gerenciar Containers



docker run -it --name meu-container ubuntu bash # Cria e inicia container

docker ps -a                                   # Lista containers (todos)

docker exec -it meu-container bash             # Executa comando no container

docker stop meu-container                      # Para container

docker start meu-container                     # Inicia container

docker rm meu-container                        # Remove container



### Persistir Dados



docker volume create meu-volume                # Cria volume nomeado

docker run -v /dados/app:/app ...             # Monta volume/diretório



### Redes



docker network create minha-rede               # Cria rede customizada



### Otimização



docker system prune                           # Limpa recursos não utilizados



## **📝 DOCKERFILE - EXEMPLO BASE**



FROM ubuntu:latest



RUN apt-get update \&\& \\

&nbsp;   apt-get install -y build-essential nano \&\& \\

&nbsp;   rm -rf /var/lib/apt/lists/\*



COPY Exemplo2.c /app/Exemplo2.c



WORKDIR /app



## **🚀 DOCKERFILE - VERSÃO APRIMORADA**



\# Usa versão específica e mais leve

FROM ubuntu:22.04



\# Instala dependências e limpa em único passo

RUN apt-get update \&\& \\

&nbsp;   apt-get install -y --no-install-recommends build-essential nano \&\& \\

&nbsp;   apt-get clean \&\& \\

&nbsp;   rm -rf /var/lib/apt/lists/\*



\# Cria e muda para usuário não-root (segurança)

RUN useradd -m appuser

WORKDIR /app

COPY --chown=appuser:appuser Exemplo2.c /app/Exemplo2.c

USER appuser



\# Compila o programa

RUN gcc -o Exemplo2 Exemplo2.c



\# Define comando padrão

CMD \["./Exemplo2"]



## **💡 PRÁTICAS RECOMENDADAS**



1\. Imagens Base

* Use versões específicas em vez de latest
* Prefira variantes -slim ou -alpine
* Use imagens oficiais (mais seguras)



2\. Otimização

* Combine comandos RUN para reduzir camadas
* Use .dockerignore para excluir arquivos desnecessários
* Limpe caches de pacotes no mesmo RUN



3\. Segurança

* Execute como usuário não-root
* Use --no-install-recommends para instalar menos pacotes
* Atualize regularmente as imagens base



4\. Saúde do Container



HEALTHCHECK --interval=30s --timeout=3s \\

&nbsp; CMD curl -f http://localhost/ || exit 1



## **🔧 COMANDOS PARA DESENVOLVIMENTO**



docker logs -f nome\_container          # Ver logs em tempo real

docker inspect nome\_container          # Inspecionar detalhes

docker stats                           # Uso de recursos em tempo real

docker exec -it nome\_container bash    # Acessar container (debugging)



## **📊 ARQUITETURA DOCKER**



Docker Daemon: Servidor que gerencia containers



Docker Client: Interface de linha de comando



Docker Registry: Repositório de imagens (Docker Hub)



Docker Images: Modelo read-only para criar containers



Docker Containers: Instância executável de uma imagem



## **🗂️ ESTRUTURA DE PROJETO RECOMENDADA**



meu-projeto/

├── Dockerfile

├── .dockerignore

├── docker-compose.yml (opcional)

├── app/

│   └── código-fonte

└── README.md



## **⚠️ ARQUIVO .dockerignore**

text

.git

node\_modules

\*.log

.env

Dockerfile

README.md

