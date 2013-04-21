#include <stdio.h>
#include <string.h>

#define MAX_INPUT 31

int main(int argc, char *argv[]) {
  
	unsigned MAX, MASK, NUM;
    int i, j;

    /* Armazena a string de entrada. */
    char *input[MAX_INPUT];

	for(i =0; i < argc -1; i++)
	{
		input[i] = argv[i + 1];
	}

    /* Armazena cada combinação. */
    char *str[MAX_INPUT];

    /* Manda o bit 1 para a n-ésima posição.
     * Os bits são invertidos para que a posição n
     * esteja com o bit zero, a fim de marcar
     * o final do processo.
     */
    MAX = ~(1 << argc -1);
		

    /* Primeiro número é o 1. */
    NUM = 1;	

    /* Quando o número alcançar MAX, o loop
     * será encerrado.
     */
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

		str[i] = NULL;		
		j = 0;

		while(str[j] != NULL)
		{
			printf("%s ", str[j]);
			j++;
		}
	
        NUM++;
		printf("\n");
    }

    return 0;
}
