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

%start Input
%%

Input:
	
	| Input Line
;

Line:
	END
	| Select END
	| OrderBy END
	| Where END
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
;

Bool_op:
	AND
	| OR
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

int yyerror(char *s) {
	printf("%s\n", s);
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
