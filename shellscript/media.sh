#!/bin/bash

cont=1
while [ $cont -ne 2 ]
do
echo -n "1º Nota: "
read nota1
echo -n "2º Nota: "
read nota2

let media="($nota1+$nota2)/2";
echo "Calculando Média do Aluno..."
sleep 2s

if [ $media -ge 6 ]; then
  echo "APROVADO | MÉDIA FINAL: $media";
else
  echo "REPROVADO! | MÉDIA FINAL: $media";
fi

echo "Deseja continuar?(1 - continuar / 2 - sair)"
read cont
done