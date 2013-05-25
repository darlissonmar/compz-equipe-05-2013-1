%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
%}

%token 	T_ALGORITMO T_STRING T_FIM_COMANDO 
%token 	T_VAR T_IDENTIFICADOR T_TIPO_ATRIBUIDOR T_IDENT_SEPARADOR T_REAL T_INTEIRO
%token 	T_INICIO T_ESCREVA T_ESCREVAL T_PARENTESE_DIR T_PARENTESE_ESQ
%token 	T_LEIA T_OPERADOR_ATRIBUICAO

%token 	T_OPERADOR_SOMA
%token 	T_OPERADOR_SUBTRACAO
%token 	T_OPERADOR_MULTIPLICACAO
%token 	T_OPERADOR_DIVISAO
%token 	T_OPERADOR_EXPONENCIACAO
%token  T_RAIZQ

%token 	T_FIMALGORITMO

%left 	T_OPERADOR_SOMA T_OPERADOR_SUBTRACAO
%left 	T_OPERADOR_MULTIPLICACAO T_OPERADOR_DIVISAO
%left 	NEG
%right 	T_OPERADOR_EXPONENCIACAO

%start 	Input
%%

Input:
	  
	| Input Algoritmo
;

Algoritmo:
	BlocoCabecalho BlocoDeclaracoes BlocoComando 
;

BlocoCabecalho:
	T_ALGORITMO T_STRING T_FIM_COMANDO
;

BlocoDeclaracoes:
	T_VAR QuebraComando ListaVariaveis T_TIPO_ATRIBUIDOR TipoVariavel T_FIM_COMANDO
;

QuebraComando:
	
	| T_FIM_COMANDO
;

ListaVariaveis:
	T_IDENTIFICADOR
	| ListaVariaveis T_IDENT_SEPARADOR T_IDENTIFICADOR
;

TipoVariavel:
	T_REAL
	| T_INTEIRO
;

BlocoComando:
	T_INICIO T_FIM_COMANDO Comandos T_FIMALGORITMO QuebraComando
;

Comandos:
	Comando
	| Comandos Comando
;

Comando:
	Leia T_FIM_COMANDO
	| Escreva T_FIM_COMANDO
	| Atribuicao T_FIM_COMANDO
;

Leia:
	T_LEIA T_PARENTESE_ESQ T_IDENTIFICADOR T_PARENTESE_DIR
;

Escreva:
	T_ESCREVA T_PARENTESE_ESQ ConteudoEscreva T_PARENTESE_DIR
	| T_ESCREVAL T_PARENTESE_ESQ ConteudoEscreva T_PARENTESE_DIR
;

ConteudoEscreva:
	T_IDENTIFICADOR OpcaoCasasDecimais
	| T_STRING
	| ConteudoEscreva T_IDENT_SEPARADOR ConteudoEscreva
;

OpcaoCasasDecimais:
	
	| T_TIPO_ATRIBUIDOR T_INTEIRO
	| T_TIPO_ATRIBUIDOR T_INTEIRO T_TIPO_ATRIBUIDOR T_INTEIRO 
;

Atribuicao:
	T_IDENTIFICADOR T_OPERADOR_ATRIBUICAO Expr

Expr:
	T_IDENTIFICADOR
	| T_INTEIRO		
	| T_REAL
	| T_PARENTESE_ESQ Expr T_PARENTESE_DIR
	| Expr Add_op Expr
	| Expr Mult_op Expr
	| T_OPERADOR_SUBTRACAO Expr %prec NEG
	| Expr T_OPERADOR_EXPONENCIACAO Expr
	| T_RAIZQ T_PARENTESE_ESQ Expr T_PARENTESE_DIR
;

Add_op:
	T_OPERADOR_SOMA
	| T_OPERADOR_SUBTRACAO
;

Mult_op:
	T_OPERADOR_MULTIPLICACAO
	| T_OPERADOR_DIVISAO
;

		
%%

extern int 	yylineno;	
extern char 	*yytext;

int yyerror(char *s) {
	printf("%s. Linha: %d. Token não esperado: %s\n", s, yylineno, yytext);
}

int main(int ac, char **av) {
	extern FILE *yyin;

	if(ac > 1 && (yyin = fopen(av[1], "r")) == NULL) {
		perror(av[1]);
		exit(1);
	}

	if(!yyparse())
		printf("O algoritmo é valido!\n");
	else
		printf("Existem erros no algoritmo.\n");
}
