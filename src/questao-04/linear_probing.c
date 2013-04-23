#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int M;
int *tab;
/*Tamanho da tabela Hash*/
#define M 10
#define ran_max 100
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

	campoVazio.indice = 0;
	campoVazio.valor = 0;

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


int main(void) {
	int c,v,j,s;
	struct campo resultado;

	 /*inicia a tabela com elementos*/
	tab = malloc(M * sizeof (ran_max));

	 /* inicializar o gerador de números aleatórios */
    srand(time(NULL));
    /* para gerar números aleatórios de 0 a 10(temporario para teste) */
	    for (j=0; j< M; j++)
	     {
			  v = (rand() % ran_max);
			  c = hash(v);

			  printf("%d[%d],",v,c);
			     while (tab[c] != 0)
			        c = (c + 1) % M;
			     tab[c] = v;
	     }
	    /*imprime o resultado*/
	    printf("\n");
	    for (s = 0; s < M; ++s) {
	    	printf("%d,",tab[s]);
		}

    resultado =  busca(tab);
    printf("%d[%d]",resultado.valor,resultado.indice);
	return 0;
}



