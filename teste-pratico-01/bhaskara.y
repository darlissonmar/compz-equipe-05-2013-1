%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
%}

%token 	T_ALGORITMO T_STRING T_FIM_COMANDO 
%token 	T_VAR T_IDENTIFICADOR T_TIPO_ATRIBUIDOR T_REAL T_INTEIRO
%token 	T_INICIO T_ESCREVA T_ESCREVAL T_PARENTESE_DIR T_PARENTESE_ESQ
%token 	T_LEIA T_OPERADOR_ATRIBUICAO

%token 	T_OPERADOR_SOMA
%token 	T_OPERADOR_SUBTRACAO
%token 	T_OPERADOR_MULTIPLICACAO
%token 	T_OPERADOR_DIVISAO
%token 	T_OPERADOR_EXPONENCIACAO

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
	| Comandos T_FIM_COMANDO Comando
;

Comando:
	Leia



Expr:
	Identificador
	| INTEIRO		
	| REAL
	| TEXTO
	| PARENTESE_ESQ Expr PARENTESE_DIR
	| Expr Bool_op Expr
	| Expr Comp_op Expr	
	| Expr Add_op Expr
	| Expr Mult_op Expr
	| MINUS Expr %prec NEG
	| NOT Expr	
	| Expr Comp_op PARENTESE_ESQ Select PARENTESE_DIR
;

Bool_op:
	AND
	| OR
	| XOR
;

Comp_op:
	IGUAL
	| DIFERENTE
	| MENOR
	| MENOR_IGUAL
	| MAIOR
	| MAIOR_IGUAL
;

Add_op:
	PLUS
	| MINUS
;

Mult_op:
	ASTERISCO
	| DIVIDE
;

Identificador:
	IDENTIFICADOR
	| IDENTIFICADOR_COM_TABELA
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
		printf("Todas as cláusulas SQL são válidas!\n");
	else
		printf("Existem erros de SQL.\n");
}
