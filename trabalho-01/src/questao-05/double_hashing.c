#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define VALOR_NULO -1 //Inteiro que representa vazio ou NULL
#define TAM_TABELA 100000 //Tamanho da tabela especificado 10^5

/*Primeira função hash que é trivial*/
#define FUNCAO_HASHING (valorEntrada % TAM_TABELA)

/*Segunda função hash que determina o salto para uma posição possivelmente vazia da tabela*/
#define FUNCAO_DOUBLE_HASHING ((valorEntrada % 2)*2 +1)

/** Estrutura para o retorno da busca, trazendo valor e índice do elemento encontrado **/
struct elementoTabela
{
    int indice;
    int valor;
} elementoTabela;

//Array que representa a tabela hash
int tabelaHash[TAM_TABELA];

int quantidadeValoresInseridos=0;
struct elementoTabela valorEncontrado = {VALOR_NULO, VALOR_NULO};

/** Chamada da primeira função hash **/
int gerar_hashing (int valorEntrada)
{
    return FUNCAO_HASHING;
}

/** Chamada da segunda função hash**/
int gerar_double_hashing (int valorEntrada)
{
    return FUNCAO_DOUBLE_HASHING;
}

/** Função: inserir_valor_tabela
 * -------------------------------
 * Insere um valor na tabela hash utilizando a técnica
 * double hashing para o tratamento de colisões
 *
 * valorDeEntrada: valor a ser inserido na tabela
**/
void inserir_valor_tabela (int valorEntrada)
{
    int indice = gerar_hashing (valorEntrada);
    int salto = gerar_double_hashing (valorEntrada);

    while (tabelaHash[indice]!=VALOR_NULO)
    {
        indice = (indice + salto) % TAM_TABELA ;
    }

    tabelaHash[indice] = valorEntrada;
    quantidadeValoresInseridos++;
}

/** Função: buscar_valor
 * -----------------------
 * Realiza a busca pelo valor de entrada, interrompendo
 * caso haja um número de tentativas igual ao número de elementos
 * inseridos afim de envitar loop infinito caso o valor não esteja
 * na tabela hash
 *
 * valorDeEntrada: valor que se deseja buscar
 *
 * retorno: estrutura que contém o par índice/valor do elemento
 * encontrado.
 **/
struct elementoTabela buscar_valor (int valorEntrada)
{
    int indice = gerar_hashing (valorEntrada);
    int salto = gerar_double_hashing (valorEntrada);
    int tentativasDeBusca=0;
    while (tabelaHash[indice]!=VALOR_NULO)
    {
        if (tabelaHash[indice]==valorEntrada)
        {
            valorEncontrado.indice=indice;
            valorEncontrado.valor= tabelaHash[indice];
        }
        if (tentativasDeBusca>=quantidadeValoresInseridos)
            break;
        tentativasDeBusca++;
        indice = (indice + salto) % TAM_TABELA;
    }

    return valorEncontrado;
}

/**Função: inicializar_tabela
 * ------------------------------
 * Marca todas as posições da tabela hash com valor que
 * representa vazio.
 **/
void inicializar_tabela()
{
    int i=0;
    for (i=0; i< TAM_TABELA; i++)
    {
        tabelaHash[i] = VALOR_NULO;
    }
}

/**Função: carregar_dados_na_tabela
 * ----------------------------------
 * Preenche a tabela com os dados do arquivo de entrada.
 *
 * nomeArquivo: nome do arquivo que contém os dados
 * a serem carregados
 **/
void carregar_dados_na_tabela(const char *nomeArquivo)
{
    freopen(nomeArquivo, "r", stdin);

    int numeroAtual=0;
    while (scanf("%d ", &numeroAtual) != EOF)
    {
        inserir_valor_tabela(numeroAtual);

        /*Evita que haja estouro caso a quantidade de dados
         no arquivo seja maior que a tabela hash*/
        if(quantidadeValoresInseridos==TAM_TABELA)
            break;
    }

    fclose(stdin);
}

int main (int argc, char *argv[])
{

    if (argc<3)
    {
        printf ( "Parâmetros inválidos!\nUtilize: ./double_hashing <arquivo_com_dados> <numero_para_busca>\n" );
        return 1;
    }
    else
    {
        srand (time(NULL));
        inicializar_tabela();
        printf ("Ambiente inicializado...\n");

        const char *nomeArquivo = (const char*)argv[1];
        int valorBuscado = atoi((const char*)argv[2]);

        carregar_dados_na_tabela(nomeArquivo);
        printf ("Dados carregados...\n");

        struct elementoTabela retornoBusca = buscar_valor(valorBuscado);

        if (retornoBusca.valor!=VALOR_NULO)
        {
            printf("Valor [%d] encontrado no índice %d\n", retornoBusca.valor, retornoBusca.indice);
        }
        else
        {
            printf("O valor desejado não existe na tabela.\n");
        }
        return 0;
    }
}
