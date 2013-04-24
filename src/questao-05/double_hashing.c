#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALOR_ENTRADA 100

#define VALOR_NULO -1
#define TAM_HASH 10
#define FUNCAO_HASHING (valor_entrada % TAM_HASH)

#define FUNCAO_DOUBLE_HASHING ((valor_entrada % 2)*2 +7)

int tabela_hash[TAM_HASH];

int gerar_hashing ( int valor_entrada )
{
    return FUNCAO_HASHING;
}

int gerar_double_hashing ( int valor_entrada )
{
    return FUNCAO_DOUBLE_HASHING;
}

void inserir_valor_tabela ( int valor_entrada )
{
    int indice = gerar_hashing ( valor_entrada );
    int salto = gerar_double_hashing ( valor_entrada );

    while ( tabela_hash[indice]!=-1 )
    {
        indice = ( indice + salto ) % TAM_HASH ;
        printf ( "[%d]Salto para %d\n",valor_entrada, indice ); //FIXME Apenas para uso em Debug
        salto=gerar_double_hashing ( indice );
    }
    tabela_hash[indice] = valor_entrada;
}

int buscar_valor ( int valor_entrada )
{
    int indice = gerar_hashing ( valor_entrada );
    int salto = gerar_double_hashing ( valor_entrada );

    while ( tabela_hash[indice]!=VALOR_NULO )
    {
        if ( tabela_hash[indice]==valor_entrada )
            return tabela_hash[indice];
        indice = ( ( indice + salto ) % TAM_HASH );
    }

    return VALOR_NULO;
}

int gerar_numero_randomico()
{
    return rand() % MAX_VALOR_ENTRADA;
}

void inicializar_tabela()
{
    int i=0;
    for ( i=0; i< TAM_HASH; i++ )
    {
        tabela_hash[i] = VALOR_NULO;
    }
}

int main ( int argc, char *argv[] )
{
    srand ( time ( NULL ) );
    inicializar_tabela();
    printf ( "Ambiente inicializado!\n" );

    int i=0;

    for ( i=0; i< TAM_HASH; i++ )
    {
        inserir_valor_tabela ( gerar_numero_randomico() );
    }

    for ( i=0; i< TAM_HASH; i++ )
    {
        printf ( "Valor da tabela[%d]: %d \n", i, tabela_hash[i] );
    }

    return 0;
}