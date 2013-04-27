#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 31 //Máximo de valores permitidos para o conjunto principal

/**
 * Funcao: mostar_particao
 * Mostra as particoes correspondentes montadas no array particionador
 * particionador: vetor contendo as regras de particionamento
 * qntNumeros: quantidade de números para gerar o conjunto principal
 *	Ex: qntNumeros==3, gera {1,2,3} como conjunto principal 
 **/
void exibir_particao(int *particionador, int qntNumeros) 
{
	int numeroParticao = 1;
	int i;
	
	//Obtem o número da maior particao
	for (i = 0; i < qntNumeros; i++)
		if (particionador[i] > numeroParticao)
			numeroParticao = particionador[i];

	//Itera sobre todas os numeros de particoes	
	for (numeroParticao; numeroParticao >= 1; numeroParticao--) {
		printf("{");		
		//Percorre o particionador e ...
		for (i = 0; i < qntNumeros; ++i)
			//Exibe os valores que pertencem à particao atual
			if (particionador[i] == numeroParticao)
				printf("%d, ", i + 1);
		printf("\b\b} ");
	}
	printf("\n");
}

/**
 * Funcao: proxima_combinacao_subconjuntos
 * Gera a proxima combinacao de subconjuntos no vetor particionador permitindo sua impressao.
 * Ex: 1 1 1, 2 1 1 , 2 2 1, 3 2 1, 2 1 2, 
 * 
 * particionador: vetor contendo as regras de particao
 * maiorPAteI: contem o maior valor de particao ate i do vetor particionador
 * qntNumeros: total de elementos do conjunto principal
 * 
 */
char proxima_combinacao_subconjuntos(int *particionador, int *maiorPAteI, int qntNumeros) {

	int i = 0;
	//Incrementa a primeira posicao do particionador
	particionador[i]++;
	
	//Incrementa os valores do particionador até encontrar valor em particionador[i] maior
	//maiorPateI[i]
	while ((i < qntNumeros - 1) && (particionador[i] > maiorPAteI[i+1] + 1)) 
	{
		//Regride a posicao anterior e incrementa a próxima
		particionador[i] = 1;
		++particionador[++i];
	}
	
	//Chegou ao fim do vetor particionador, portanto nao existem mais combinacoes
	if (i == qntNumeros - 1)
		return 0;
	
	//Caso existam mais combinacoes, s[i] conterá o maior indice de particao
	if( particionador[i] > maiorPAteI[i] )
	  maiorPAteI[i] = particionador[i];
	int j=0;
	for (j = i - 1; j >= 0; --j)
	{
	  maiorPAteI[j] = maiorPAteI[i];
	}	
	return 1;
}

int main(int argc, char *argv[]) {
	if (argc<2)
	{
	    printf("Utilize ./mypart <tamanho_conjunto>\n");
	    return 1;
	}
  
	int particionador[MAX_NUM]; //Contém as regras de particao
	int maiorPAteI[MAX_NUM];

	int qntNumeros = atoi(argv[1]);
	int i;
	
	//Todos os elementos se encontram no mesmo conjunto na primeira iteracao
	for (i = 0; i < qntNumeros; ++i) {
		particionador[i] = 1;
		maiorPAteI[i] = 1;
	}
	
	printf("As particoes para {");
	for (i=1; i<=qntNumeros; i++)
	   printf(" %d", i);
	printf(" } são:\n");
	

	//Exibe a primeira particao com todos os elementos
	exibir_particao(particionador, qntNumeros);

	//Exibe cada conjunto de particoes possiveis
	while (proxima_combinacao_subconjuntos(particionador, maiorPAteI, qntNumeros))
		exibir_particao(particionador, qntNumeros);

	return 0;
}
