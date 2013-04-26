/*
 UNIVERSIDADE DO ESTADO DO AMAZONAS - UEA
 * Ecola Superior de Tecnologia
 * Engenharia da Computação
 * Professor: Jucimar Junior
 * Disciplina: Compiladores
 *
 * Equipe 05:
 * -
 * - Daniel Henrique Braz Aquino
 * - Darlisson Marinho de Jesus - 0825080027
 * - Iasmim Cunha
 * - Leandro Bentes
 * - Williams Araujo
 *
 * 	QUESTAO-03 - LISTA DE EXERCICIOS DE COMPILADORES
 *  Escreva um programa que insira 10ˆ5 inteiros aleatórios não negativos,
 * 	de valor inferior a 10^6 em uma hash table de tamanho 10^5. Os nros de-
 * 	verão ser inseridos usando uma funcão hash definida pelo aluno. Crie uma
 * 	função pra procurar um valor na hash table.
 *
*/

#include <stdlib.h>
#include <stdio.h>
#define TABELA_TAM 100000		/*tamanho da tabela hash 10^5 como especificado*/

typedef struct celula *tabela_link;

struct celula
{
	int valor;
	tabela_link proximo;
}celula;

tabela_link tabela_hash[TABELA_TAM];
int numero_colisoes = 0;

/*
* Funcao: buscar_valor
* ----------------------------
Retorna o valor buscado na tabela hash
*
valor: um numero inteiro positivo menor que 10^6
*
retorno: um inteiro positivo se o valor existir na
 	 	 tabela hash caso contrario retorna ou um
 	 	 inteiro negativo .
*/

int buscar_valor(int valor)
{
	int h = gerar_hash(valor);
	tabela_link tab = tabela_hash[h];

	while( tab != NULL )
	{
		if( valor == tab->valor )
		{
			break;
		}
		tab = tab->proximo;
	}

	if(tab != NULL)
		return tab->valor;
	return -1;
}

/*
* Funcao: inserir_valor
* ----------------------------
*
Insere na tabela hash uma nova entrada e usa
a abordagem de 'encadeamento separado' para tratar as
colisoes.
*
valor: um numero inteiro positivo menor que 10^6
*
retorno: nao retorna nada
*/

void inserir_valor(int valor)
{
	int h = gerar_hash(valor);
	tabela_link tab = tabela_hash[h];

	for( tab = tabela_hash[h]; tab != NULL; tab = tab->proximo )
	{
		if ( valor == tab->valor )
		{
			//printf("COLISAO[%d]: Ao inserir [%d], no indice [%d] ja existe um outro valor\n",++numero_colisoes, valor, h);
			break;
		}
	}

	if( tab == NULL )
	{
		tabela_link nova_entrada = malloc(sizeof (celula));
		nova_entrada->valor = valor;
		nova_entrada->proximo = tabela_hash[h];
		tabela_hash[h] = nova_entrada;
	}
}


/*
* Funcao: inicializar_tabela
* ----------------------------
*
Inicializa a tabela hash com valores nulos.
*
retorno: nao retorna nada
*/
void inicializar_tabela()
{
	int i = 0;
	for( i = 0; i < TABELA_TAM; i++ )
	{
		tabela_hash[i] = NULL;
	}
}

/*
* Funcao: imprimir_tabela
* ----------------------------
*
Imprime a tabela hash, mostrando indice hash e
valor armazenado no respectivo indice.
*
retorno: nao retorna nada
*/
void imprimir_tabela()
{
	tabela_link aux;
	int i = 0;
	int n = 0;
	printf("[chave]-----------[valor]");
	for(i = 0; i < TABELA_TAM; i++)
	{
		aux = tabela_hash[i];
		for( aux = tabela_hash[i]; aux != NULL; aux = aux->proximo)
		{
		    printf("[%d]-----------[%d]\n", i, aux->valor);
		}
	}
}

/*
* Funcao: total_celulas_nulas
* ----------------------------
*
Conta o numero de entradas na tabela hash que
nao foram usados.
*
retorno: nao retorna nada
*/
void total_celulas_nulas(){
	int i = 0;
	int count = 0;
	for ( i= 0; i < TABELA_TAM; i++)
	{
		if(tabela_hash[i] == NULL)
		{
			++count;
			printf("%d\n", i);
		}
	}
	printf("Existem [%d] posicoes nulas", count);
}

/*
* Funcao: gerar_hash
* ----------------------------
*
Funcao hash que recebe um valor inteiro e retor-
na outro inteiro como resultado do resto da divi-
sao desse valor pelo tamanho da tabela.
*
valor: um numero inteiro positivo menor que 10^6.
*
retorno: um inteiro positivo.
*/


int gerar_hash(int valor)
{
	return (int) (valor % TABELA_TAM);
}

/* A tabela hash e preenchida por valores inteiros de um arquivo
 * passado como argumento.
 *
 * Apos carregar os dados, a funcao principal fica em loop
 * solicitando valores a serem buscados na tabela hash.
 *
 * Para sair do programa eh necessario digitar o valor '0' (zero).
 * */


int main(int argc,  char *argv[])
{
	FILE *arquivo_entrada;
	int numero;

	if( argc < 2 )
	{
		printf("**Erro: O arquivo de entrada eh necessario.\n");
		exit(EXIT_FAILURE);

	}

	if( (arquivo_entrada = fopen(argv[1],"r")) == NULL)
	  {
	    printf("**Erro ao abrir arquivo!\n");
	    exit(EXIT_FAILURE);
	  }

	inicializar_tabela();

	do
	{
		fscanf(arquivo_entrada, "%d", &numero);
		inserir_valor(numero);

	}while (!feof(arquivo_entrada));
	fclose(arquivo_entrada);

	/* metodos auxiliar para visualizar as colisoes e a eficiencia da dispersao*/
	//imprimir_tabela();
	//total_celulas_nulas();

	numero = 0;
	while (1)
	{
		puts("Insira um valor a ser buscado na hash table(digite '0' finalizar) > ");
		scanf("%d", &numero);
		if (numero == 0)
			exit(EXIT_SUCCESS);

		if (buscar_valor(numero) != -1)
		{
			printf("O numero [%d] foi encontrado.\n", numero);
		} else
			{
				printf("O numero [%d] nao foi encontrado.\n", numero);
			}
	}
	return 0;
}
