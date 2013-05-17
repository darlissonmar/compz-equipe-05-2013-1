%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
%}

%token SELECT FROM WHERE AS
%token AND OR NOT
%token ORDER BY ASC DESC
%token IDENTIFICADOR IDENTIFICADOR_COM_TABELA
%token INTEIRO REAL TEXTO

%token PLUS
%token MINUS
%token DIVIDE

%token ASTERISCO
%token SEPARADOR
%token PARENTESE_ESQ
%token PARENTESE_DIR
%token IGUAL
%token DIFERENTE
%token MENOR
%token MENOR_IGUAL
%token MAIOR
%token MAIOR_IGUAL
%token END

%left OR
%left XOR
%left AND
%left NOT
%left IGUAL DIFERENTE MENOR MENOR_IGUAL MAIOR MAIOR_IGUAL
%left PLUS MINUS
%left DIVIDE ASTERISCO

%nonassoc NEG

%start Input
%%

Input:
	  
	| Input Query END
;

Query:
	Select
	| Select OrderBy
	| Select Where OrderBy
;

Select:
	SELECT Campos FROM Tabelas
;

Campos:
	ASTERISCO
	| Lista_Campos
;

Lista_Campos:
	Identificador
	| Lista_Campos SEPARADOR Identificador
;

Tabelas:
	Tabela
	| Tabelas SEPARADOR Tabela
;

Tabela:
	IDENTIFICADOR
	| IDENTIFICADOR AS IDENTIFICADOR
;

OrderBy:
	ORDER BY Campos_OrderBy
;

Campos_OrderBy:
	Campo_OrderBy
	| Campos_OrderBy SEPARADOR Campo_OrderBy
;

Campo_OrderBy:
	Identificador
	| Identificador ASC
	| Identificador DESC
;

Where:
	WHERE Expr
;

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
		printf("SQL parse worked\n");
	else
		printf("SQL parse failed\n");
}
