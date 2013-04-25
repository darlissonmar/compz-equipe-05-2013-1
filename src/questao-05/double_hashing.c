#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define VALOR_NULO -1
#define TAM_TABELA 100000 //Tamanho da tabela especificado 10^5

#define FUNCAO_HASHING (valorEntrada % TAM_TABELA)
#define FUNCAO_DOUBLE_HASHING ((valorEntrada % 2)*2 +1)

struct elementoTabela
{
    int indice;
    int valor;
} elementoTabela;

int tabelaHash[TAM_TABELA];
int quantidadeValoresInseridos=0;
struct elementoTabela valorEncontrado = {VALOR_NULO, VALOR_NULO};


int gerar_hashing (int valorEntrada)
{
    return FUNCAO_HASHING;
}

int gerar_double_hashing (int valorEntrada)
{
    return FUNCAO_DOUBLE_HASHING;
}

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

void inicializar_tabela()
{
    int i=0;
    for (i=0; i< TAM_TABELA; i++)
    {
        tabelaHash[i] = VALOR_NULO;
    }
}

void carregar_dados_na_tabela(const char *nomeArquivo)
{
    freopen(nomeArquivo, "r", stdin);

    int numeroAtual=0;
    while (scanf("%d ", &numeroAtual) != EOF)
    {
        inserir_valor_tabela(numeroAtual);
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
