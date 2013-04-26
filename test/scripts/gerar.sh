# ! /etc/bash

# Script para gerar um arquivo ASCII com numeros aleatorios 
# E contar se existe numero repetido na sequencia gerada.


# Voce pode inserir um nome para o arquivo de saida
# Caso nao insira, o arquivo de saida sera nomeado como
# 'aleatorios.output

if [ $# -ne 1 ]; then
	arquivo_nome='aleatorios.output'
	
else 
	arquivo_nome=$1'.output'
fi

./aleatorios > $arquivo_nome

echo "Total de numeros repetidos em: " $arquivo_nome 
cat $arquivo_nome | uniq -d | wc -l
