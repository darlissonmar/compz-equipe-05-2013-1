#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int M;
#define M 10
#define ran_max 10
#define hash(v) (v % 5)            /*numero primo para melhor dispersão */

int *tab;

int main(void) {
	int i,c,v,j,h,s;

	tab = malloc(M * sizeof (ran_max));      /*inicia a tabela com elementos*/

    srand(time(NULL));      		        /* inicializar o gerador de números aleatórios */
	    for (j=0; j< M; j++)     		    /* com time(NULL)  */
	     {
			  v = (rand() % 10);
			  c = hash(v);                  /* para gerar números aleatórios de 0 a 10(temporario para teste) */

			  printf("%d,",v);
			     while (tab[c] != 0)
			        c = (c + 1) % M;
			     tab[c] = v;
	     }

	    printf("\n");
	    for (s = 0; s < M; ++s) {   	/*imprime o resultado*/
	    	printf("%d,",tab[s]);
		}

	return 0;
}
