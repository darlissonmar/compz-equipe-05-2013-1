%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token SELECT FROM WHERE AS
%token AND OR NOT
%token ORDER_BY ASC DESC
%token IDENTIFICADOR
%token INTEIRO REAL TEXTO

%token ASTERISCO
%token SEPARADOR
%token PARENTESE_ESQ
%token PARENTESE_DIR
%token IGUAL
%token DIFERENTE
%token MENOR
%token MAIOR_IGUAL
%token END

%start Input
%%

Input:
	
	| Input Line
;

Line:
	END
	| Query END
;

Query:
	END
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
