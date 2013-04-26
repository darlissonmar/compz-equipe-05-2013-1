#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int M;
int *tab;
/*Tamanho da tabela Hash*/
#define NUMERO_MAX 999999 // < 10^6
#define M 100000 // 10^5
/*Função hash para definir index*/
#define hash(v) (v % M)
/*estrutura do campo do vetor*/
struct campo
{
 int indice;
 int valor;
}campo;

/*metódo de busca na tabela hash*/
struct campo busca(int v)
{
	int b;
	struct campo campoVazio;

	campoVazio.indice = -1;
	campoVazio.valor = -1;

	struct campo campoOcupado;
		b = hash(v);
		while (tab[b] != 0)
		{
			 if (tab[b] == v)
			  {
			   campoOcupado.indice = b;
			   campoOcupado.valor = tab[b];
			   return  campoOcupado;
			  }
			else
			  {
			   b = (b + 1) % M;
			  }
		}
	 return  campoVazio;
}

int *ler(const char *arquivo)
{
	    FILE *arq;
	    int j;
		int *valores_entrada;
		valores_entrada = malloc(M * sizeof (NUMERO_MAX));
	    char linha[100];
		arq = fopen (arquivo, "r");
		if(arq != NULL)
		{

		    while(fgets(linha, sizeof linha, arq) != NULL)
		    {
		        int len = strlen(linha) - 1;
		        if (linha[len] == '\n') /*Verifica se o ultimo caracter é um enter*/
		                linha[len] = 0; /*Isso substitui o enter por um '\0', que indica o fim da string*/
		        if(strlen(linha) > 0)
		        {
		        	valores_entrada[j] = atoi(&linha); /*Converte um char para int*/
		            j++;
		        }
		    }
		    fclose(arq);
		    return valores_entrada;
		}
		else
		{
			 puts("Erro ao tentar abrir arquivo");
			 return 0;
		}
}

int main(int argc, char *argv[]) {
	int c,j,s;
	int *valores_aleatorios;
	struct campo resultado;

	 /*inicia a tabela com elementos*/
	tab = malloc(M * sizeof (NUMERO_MAX));
	valores_aleatorios = malloc(M * sizeof (NUMERO_MAX));
	//Pega os valores aleatorios gerados no script
	valores_aleatorios = ler((const char*)argv[1]);

	puts("Iniciando...\n\n");
	    for (j=0; j< M; j++)
	     {
			  c = hash(valores_aleatorios[j]);
			     while (tab[c] != 0)
			        c = (c + 1) % M;
			     tab[c] = valores_aleatorios[j];
	     }
    puts("Tabela Hash preenchida!");

    resultado =  busca(atoi((const char*)argv[2]));

    if(resultado.indice != -1)
      printf("\nValor da tabela[%d]:%d\n",resultado.indice,resultado.valor);
    else
      puts("Valor não encontrado\n");
	return 0;
}



