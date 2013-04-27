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


void inicializar_tabela()
{
    int i=0;
    for (i=0; i< M; i++)
    {
        tab[i] = -1;
    }
}


/*
 * Função:busca_tabela
 *
 * metódo de busca na tabela hash
 * compara todos os valores da tabela M vezes,onde M = qtd de itens na tabela,
 * com o valor da busca,caso este exista retorna
 * assim que encontrar ,caso não retorna valor nulo -1
 *
 * */
struct campo busca_tabela(int v)
{
	int b;
	struct campo campoVazio;

	puts("\nBuscando...\n");
	campoVazio.indice = -1;
	campoVazio.valor = -1;

	int tentativas_busca = 0;
	struct campo campoOcupado;
		b = hash(v);//gera o indice do valor
		while (tentativas_busca < M)
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

			 tentativas_busca++;
		}
     printf("\nTentativas de busca:%d\n",tentativas_busca);
	 return  campoVazio;
}

/*
 * Função:ler_arquivo
 * Ler o arquivo ,cujo caminho vem por parametro no argv
 * e coloca em um vetor de interos intermediario
 *
 * */
int *ler_arquivo(const char *arquivo)
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
		        if (linha[len] == '\n')
		                linha[len] = 0;
		        if(strlen(linha) > 0)
		        {
		        	valores_entrada[j] = atoi(&linha);
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
	valores_aleatorios = ler_arquivo((const char*)argv[1]);

	inicializar_tabela();
	int inseridos = 0;
	puts("Iniciando...\n\n");
	    for (j=0; j< M; j++)
	     {
			  c = hash(valores_aleatorios[j]);
			     while (tab[c] != -1)
			        c = (c + 1) % M;
			     tab[c] = valores_aleatorios[j];

			     inseridos++;
	     }
    printf("Tabela Hash preenchida!\nquantidade de elementos inseridos:%d\n\n",inseridos);

    resultado =  busca_tabela(atoi((const char*)argv[2]));

    if(resultado.indice != -1)
      printf("\nValor da tabela[%d]:%d\n",resultado.indice,resultado.valor);
    else
      puts("Valor não encontrado\n");
	return 0;
}


