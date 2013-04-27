#include <stdio.h>

/**
 * Funcao: print_part
 * Mostra as particoes correspondentes montadas no array mypart
 * mypart: vetor contendo as regras de particionamento
 * qntNumeros: quantidade de números para gerar o conjunto principal
 * Ex: qntNumeros==3, gera {1,2,3} como conjunto principal 
 **/
void print_part(int *mypart, int n)
{
	int print, subset, i, j;	
	
	//Obtem o número da maior particao
	subset = 1;
	for (i = 0; i < n; i++)
	{
		if (mypart[i] > subset)
		{
			subset = mypart[i];
		}
	}   		

	//Itera sobre todas os numeros de particoes		
	for (j = subset; j >= 1; j--)
	{
		print = 0;						
		printf("{");
		
		//Percorre o particionador e ...						
		for (i = 0; i < n; i++)
		{	
			//Exibe os valores que pertencem à particao atual			
			if (mypart[i] == j)
			{						
				print++;			
				if(print >= 2)
				{		
					printf(",%d", i + 1);		
				} 
				else
				{			
					printf("%d", i + 1);
				}
			}
		}
		printf("}");

		if(j >= 1)
		{
			printf("\t");
		}
	}

	printf("\n");
}

/**
 * Funcao: has_part
 * Gera a proxima combinacao de subconjuntos no vetor particionador permitindo sua impressao.
 * Ex: 1 1 1, 2 1 1 , 2 2 1, 3 2 1, 2 1 2, 
 * 
 * mypart: vetor contendo as regras de particao
 * n: total de elementos do conjunto principal
 */
int has_part(int *mypart, int n)
{	
	int i, j;
	
	i = 0;
	//Incrementa a primeira posicao do particionador
	mypart[i]++;
	mypart[n] = 1;


	for (j = i + 1; j < n - 1; j++)
	{
		if (mypart[j] > mypart[n])
			mypart[n] = mypart[j];
	}

	//Não há mais partições para serem impressas
	if ( mypart[0] == n + 1 )
		return 0;

	//Caso existam mais combinações, mypart[i] conterá o maior indice de particao
	while ((mypart[i] > mypart[n] + 1)) 
	{
		mypart[i] = 1;
		i++;
		mypart[i]++;
		mypart[n] = 1;
	
		for (j = i + 1; j < n - 1; ++j)
		{
			if (mypart[j] > mypart[n])
			{
				mypart[n] = mypart[j];			
			}
		}
	}

	return 1;
}	

void main(int argc, char *argv[])
{  
	int n = atoi(argv[1]);
	int mypart[n];
	
	int i;	
	for (i = 0; i < n; i++)
	{
		mypart[i] = 1;
	}
	print_part(mypart, n);
	
	while (has_part(mypart, n))
	{
		print_part(mypart, n);
	}
}
