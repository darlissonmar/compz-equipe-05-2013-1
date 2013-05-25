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

%token 	T_ABS T_ALEATORIO T_ARCCOS T_ARCSEN T_ARCTAN T_ATE T_ASC T_ARQUIVO T_CARAC     
%token 	T_CARACPNUM T_CARACTERE T_CASO T_COMPR T_COPIA T_COS T_COTAN T_CRONOMETRO     
%token 	T_DE T_DEBUG 

%token 	T_DECLARE T_ECO T_ENQUANTO T_ENTAO T_ESCOLHA T_EXP T_FACA  
%token 	T_FALSO T_FIMENQUANTO T_FIMESCOLHA T_FIMFUNCAO T_FIMPARA  
%token 	T_FIMPROCEDIMENTO T_FIMREPITA T_FIMSE T_FUNCAO T_GRAUPRAD  
%token 	T_INT T_INTERROMPA T_LIMPATELA T_LITERAL T_LOG T_LOGICO  
%token 	T_MAIUSC T_MENSAGEM T_MINUSC T_NUMPCARAC T_NUMERICO  
%token 	T_OUTROCASO T_PARA T_PASSO T_PAUSA T_PI T_POS T_PROCEDIMENTO  
%token 	T_QUAD T_RADPGRAU T_RAND T_RANDI T_REPITA T_RETORNE 
%token 	T_SE T_SEN T_SENAO T_TAN T_TIMER T_VETOR T_VERDADEIRO  
%token 	T_OPERADOR_DIVISAO_INT T_OPERADOR_DIVISAO_RESTO T_OPERADOR_IGUAL  
%token 	T_OPERADOR_DIFERENTE T_OPERADOR_MENOR T_OPERADOR_MAIOR T_OPERADOR_MENOR_IGUAL  
%token 	T_OPERADOR_MAIOR_IGUAL T_COLCHETE_ESQ T_COLCHETE_DIR T_VETOR_INTERVALO  
%token 	T_NUMERO_INTEIRO T_NUMERO_REAL T_OP_LOGICO_E T_OP_LOGICO_XOU  
%token 	T_OP_LOGICO_NAO T_OP_LOGICO_OU T_INVALIDO   


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
	T_ALGORITMO T_STRING FimComando
;

BlocoDeclaracoes:
	T_VAR QuebraComando ListaVariaveis T_TIPO_ATRIBUIDOR TipoVariavel FimComando
;

QuebraComando:
	
	| FimComando
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
	T_INICIO FimComando Comandos T_FIMALGORITMO QuebraComando
;

Comandos:
	Comando
	| Comandos Comando
;

Comando:
	Leia FimComando
	| Escreva FimComando
	| Atribuicao FimComando
;

FimComando:
	T_FIM_COMANDO
	| FimComando T_FIM_COMANDO
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
	
	| T_TIPO_ATRIBUIDOR T_NUMERO_INTEIRO
	| T_TIPO_ATRIBUIDOR T_NUMERO_INTEIRO T_TIPO_ATRIBUIDOR T_NUMERO_INTEIRO 
;

Atribuicao:
	T_IDENTIFICADOR T_OPERADOR_ATRIBUICAO Expr

Expr:
	T_IDENTIFICADOR
	| T_NUMERO_INTEIRO		
	| T_NUMERO_REAL
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
