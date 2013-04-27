#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 31

int main(int argc, char *argv[]) {
  
	unsigned MAX, MASK, NUM;
	int i, j;

	int SIZE = atoi(argv[1]);

	/* Gerar o conjunto de entrada. */
	int input[SIZE];

	for(i =1; i <= SIZE; i++)
	{	
		input[i-1] = i;
	}

	/* Armazena cada combinação. */
	int str[MAX_INPUT];

	/* Manda o bit 1 para a n-ésima posição.
	* Os bits são invertidos para que a posição n
	* esteja com o bit zero, a fim de marcar
	* o final do processo.
	*/
	MAX = ~(1 << SIZE);


	/* Primeiro número é o 1. */
	NUM = 1;	

	/* Quando o número alcançar MAX, o loop
	* será encerrado.
	*/
	int RANGE = 1;
	while (RANGE <= SIZE)
	{
		NUM = 1;
		while ( MAX & NUM) 
		{
			MASK = 1;
			i = j = 0;

			while ( MAX & MASK ) 
			{
				/* Verdadeiro se NUM tem um bit 1
				* na posição indicada por MASK. */

				if ( NUM & MASK ) 
				{
					/* Gera a combinação em str. */
					str[i] = input[j];
					i++;
				}
				j++;
				/* Desloca a máscara */
				MASK = MASK << 1;
			}

			str[i] = -1;		
			j = 0;
			if(i == RANGE)
			{
				while(str[j] != -1)
				{
					printf("%d ", str[j]);
					j++;
				}
				printf("\n");
			}			
			NUM++;
		}
		RANGE = RANGE + 1;
	}

	return 0;
}
