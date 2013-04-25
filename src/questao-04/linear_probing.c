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
struct campo busca(int *v)
{
	int b,a;
	struct campo campoVazio;

	campoVazio.indice = -1;
	campoVazio.valor = -1;

	struct campo campoOcupado;
	printf("\nEntre com o valor para busca:");
	scanf("%d",&a);
		b = hash(a);
		while (tab[b] != 0)
		{
			 if (tab[b] == a)
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

int *ler()
{
	    FILE *arq;
		int *valores_entrada;
		valores_entrada = malloc(M * sizeof (NUMERO_MAX));
		char linha[100];
		arq = fopen ("test/scripts/linear.txt", "r");
		if(arq != NULL)
		{
			int j;
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

int main(void) {
	int c,j,s;
	int *valores_aleatorios;
	struct campo resultado;

	 /*inicia a tabela com elementos*/
	tab = malloc(M * sizeof (NUMERO_MAX));
	valores_aleatorios = malloc(M * sizeof (NUMERO_MAX));
	//Pega os valores aleatorios gerados no script
	valores_aleatorios = ler();

	    for (j=0; j< M; j++)
	     {
			  c = hash(valores_aleatorios[j]);
			  printf("%d[%d] \n",valores_aleatorios[j],c);
			     while (tab[c] != 0)
			        c = (c + 1) % M;
			     tab[c] = valores_aleatorios[j];
	     }
	    /*imprime o resultado*/
	    printf("\n");
	    for (s = 0; s < M; ++s)
	    {
	    	printf("%d[%d]\n",tab[s],s);
		}

    resultado =  busca(tab);
    printf("Valor da tabela[%d]:%d",resultado.indice,resultado.valor);
	return 0;
}



