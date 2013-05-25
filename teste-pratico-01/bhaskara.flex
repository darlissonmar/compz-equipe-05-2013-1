%option yylineno
%{
#define YYTYPE double
#include "bhaskara.tab.h"
#include <stdio.h>

#define ERRO -1

%}

T_ABS			(A|a)(B|b)(S|s)
T_ALEATORIO		(A|a)(L|l)(E|e)(A|a)(T|t)(O|o)(R|r)(I|i)(O|o)
T_ALGORITMO		(A|a)(L|l)(G|g)(O|o)(R|r)(I|i)(T|t)(M|m)(O|o)
T_ARCCOS		(A|a)(R|r)(C|c)(C|c)(O|o)(S|s)
T_ARCSEN		(A|a)(R|r)(C|c)(S|s)(E|e)(N|n)
T_ARCTAN		(A|a)(R|r)(C|c)(T|t)(A|a)(N|n)
T_ARQUIVO		(A|a)(R|r)(Q|q)(U|u)(I|i)(V|v)(O|o)
T_ASC			(A|a)(S|s)(C|c)
T_ATE			(A|a)(T|t)(E|e)
T_CARAC			(C|c)(A|a)(R|r)(A|a)(C|c)
T_CARACPNUM		(C|c)(A|a)(R|r)(A|a)(C|c)(P|p)(N|n)(U|u)(M|m)
T_CARACTERE		(C|c)(A|a)(R|r)(A|a)(C|c)(T|t)(E|e)(R|r)(E|e)
T_CASO			(C|c)(A|a)(S|s)(O|o)
T_COMPR			(C|c)(O|o)(M|m)(P|p)(R|r)
T_COPIA			(C|c)(O|o)(P|p)(I|i)(A|a)
T_COS			(C|c)(O|o)(S|s)
T_COTAN			(C|c)(O|o)(T|t)(A|a)(N|n)
T_CRONOMETRO		(C|c)(R|r)(O|o)(N|n)(O|o)(M|m)(E|e)(T|t)(R|r)(O|o)
T_DE			(D|d)(E|e)
T_DEBUG			(D|d)(E|e)(B|b)(U|u)(G|g)
T_DECLARE		(D|d)(E|e)(C|c)(L|l)(A|a)(R|r)(E|e)
T_E			(E|e)
T_ECO			(E|e)(C|c)(O|o)
T_ENQUANTO		(E|e)(N|n)(Q|q)(U|u)(A|a)(N|n)(T|t)(O|o)
T_ENTAO			(E|e)(N|n)(T|t)(A|a)(O|o)
T_ESCOLHA		(E|e)(S|s)(C|c)(O|o)(L|l)(H|h)(A|a)
T_ESCREVA		(E|e)(S|s)(C|c)(R|r)(E|e)(V|v)(A|a)
T_ESCREVAL		(E|e)(S|s)(C|c)(R|r)(E|e)(V|v)(A|a)(L|l)
T_EXP			(E|e)(X|x)(P|p)
T_FACA			(F|f)(A|a)(C|c)(A|a)
T_FALSO			(F|f)(A|a)(L|l)(S|s)(O|o)
T_FIMALGORITMO		(F|f)(I|i)(M|m)(A|a)(L|l)(G|g)(O|o)(R|r)(I|i)(T|t)(M|m)(O|o)
T_FIMENQUANTO		(F|f)(I|i)(M|m)(E|e)(N|n)(Q|q)(U|u)(A|a)(N|n)(T|t)(O|o)
T_FIMESCOLHA		(F|f)(I|i)(M|m)(E|e)(S|s)(C|c)(O|o)(L|l)(H|h)(A|a)
T_FIMFUNCAO		(F|f)(I|i)(M|m)(F|f)(U|u)(N|n)(C|c)(A|a)(O|o)
T_FIMPARA		(F|f)(I|i)(M|m)(P|p)(A|a)(R|r)(A|a)
T_FIMPROCEDIMENTO	(F|f)(I|i)(M|m)(P|p)(R|r)(O|o)(C|c)(E|e)(D|d)(I|i)(M|m)(E|e)(N|n)(T|t)(O|o)
T_FIMREPITA		(F|f)(I|i)(M|m)(R|r)(E|e)(P|p)(I|i)(T|t)(A|a)
T_FIMSE			(F|f)(I|i)(M|m)(S|s)(E|e)
T_FUNCAO		(F|f)(U|u)(N|n)(C|c)(A|a)(O|o)
T_GRAUPRAD		(G|g)(R|r)(A|a)(U|u)(P|p)(R|r)(A|a)(D|d)
T_INICIO		(I|i)(N|n)(I|i)(C|c)(I|i)(O|o)
T_INT			(I|i)(N|n)(T|t)
T_INTEIRO		(I|i)(N|n)(T|t)(E|e)(I|i)(R|r)(O|o)
T_INTERROMPA		(I|i)(N|n)(T|t)(E|e)(R|r)(R|r)(O|o)(M|m)(P|p)(A|a)
T_LEIA			(L|l)(E|e)(I|i)(A|a)
T_LIMPATELA		(L|l)(I|i)(M|m)(P|p)(A|a)(T|t)(E|e)(L|l)(A|a)
T_LITERAL		(L|l)(I|i)(T|t)(E|e)(R|r)(A|a)(L|l)
T_LOG			(L|l)(O|o)(G|g)
T_LOGICO		(L|l)(O|o)(G|g)(I|i)(C|c)(O|o)
T_MAIUSC		(M|m)(A|a)(I|i)(U|u)(S|s)(C|c)
T_MENSAGEM		(M|m)(E|e)(N|n)(S|s)(A|a)(G|g)(E|e)(M|m)
T_MINUSC		(M|m)(I|i)(N|n)(U|u)(S|s)(C|c)
T_MOD			(M|m)(O|o)(D|d)
T_NAO			(N|n)(A|a)(O|o)
T_NUMERICO		(N|n)(U|u)(M|m)(E|e)(R|r)(I|i)(C|c)(O|o)
T_NUMPCARAC		(N|n)(U|u)(M|m)(P|p)(C|c)(A|a)(R|r)(A|a)(C|c)
T_OU			(O|o)(U|u)
T_OUTROCASO		(O|o)(U|u)(T|t)(R|r)(O|o)(C|c)(A|a)(S|s)(O|o)
T_PARA			(P|p)(A|a)(R|r)(A|a)
T_PASSO			(P|p)(A|a)(S|s)(S|s)(O|o)
T_PAUSA			(P|p)(A|a)(U|u)(S|s)(A|a)
T_PI			(P|p)(I|i)
T_POS			(P|p)(O|o)(S|s)
T_PROCEDIMENTO		(P|p)(R|r)(O|o)(C|c)(E|e)(D|d)(I|i)(M|m)(E|e)(N|n)(T|t)(O|o)
T_QUAD			(Q|q)(U|u)(A|a)(D|d)
T_RADPGRAU		(R|r)(A|a)(D|d)(P|p)(G|g)(R|r)(A|a)(U|u)
T_RAIZQ			(R|r)(A|a)(I|i)(Z|z)(Q|q)
T_RAND			(R|r)(A|a)(N|n)(D|d)
T_RANDI			(R|r)(A|a)(N|n)(D|d)(I|i)
T_REAL			(R|r)(E|e)(A|a)(L|l)
T_REPITA		(R|r)(E|e)(P|p)(I|i)(T|t)(A|a)
T_RETONRE		(R|r)(E|e)(T|t)(O|o)(R|r)(N|n)(E|e)
T_SE			(S|s)(E|e)
T_SEN			(S|s)(E|e)(N|n)
T_SENAO			(S|s)(E|e)(N|n)(A|a)(O|o)
T_TAN			(T|t)(A|a)(N|n)
T_TIMER			(T|t)(I|i)(M|m)(E|e)(R|r)
T_VAR			(V|v)(A|a)(R|r)
T_VETOR			(V|v)(E|e)(T|t)(O|o)(R|r)
T_VERDADEIRO		(V|v)(E|e)(R|r)(D|d)(A|a)(D|e)(I|i)(R|r)(O|o)
T_XOU			(X|x)(O|o)(U|u)
T_COMENTARIO_UL 	"//".*(\n)?
T_COMENTARIO_ML 	\{(.*|\n)[^\}]*\}
T_NUMERO_INTEIRO	[0-9]+
T_NUMERO_REAL		[0-9]+\.[0-9]+
T_IDENTIFICADOR		[a-zA-Z\_][a-zA-Z0-9\_]*
T_INVALIDO		[0-9][a-zA-Z0-9]*
T_STRING		\".*\"
T_BRANCO		[ \t\r]*

%%
{T_STRING}		return T_STRING;
{T_ABS}			return T_ABS;
{T_ALEATORIO}		return T_ALEATORIO;
{T_ARCCOS}		return T_ARCCOS;
{T_ARCSEN}		return T_ARCSEN;
{T_ARCTAN}		return T_ARCTAN;
{T_ATE}			return T_ATE;
{T_ASC}			return T_ASC;
{T_ARQUIVO}		return T_ARQUIVO;
{T_ALGORITMO}		return T_ALGORITMO;
{T_CARAC}		return T_CARAC;
{T_CARACPNUM}		return T_CARACPNUM;
{T_CARACTERE}		return T_CARACTERE;
{T_CASO}		return T_CASO;
{T_COMPR}		return T_COMPR;
{T_COPIA}		return T_COPIA;
{T_COS}			return T_COS;
{T_COTAN}		return T_COTAN;
{T_CRONOMETRO}		return T_CRONOMETRO;
{T_DE}			return T_DE;       
{T_DEBUG}		return T_DEBUG;    
{T_DECLARE}		return T_DECLARE;  
{T_ECO}			return T_ECO;
{T_ENQUANTO}		return T_ENQUANTO;
{T_ENTAO}		return T_ENTAO;  
{T_ESCOLHA}		return T_ESCOLHA;
{T_ESCREVA}		return T_ESCREVA;
{T_ESCREVAL}		return T_ESCREVAL;
{T_EXP}			return T_EXP;
{T_FACA}		return T_FACA;   
{T_FALSO}		return T_FALSO;                 
{T_FIMALGORITMO}	return T_FIMALGORITMO;         
{T_FIMENQUANTO}		return T_FIMENQUANTO;          
{T_FIMESCOLHA}		return T_FIMESCOLHA;          
{T_FIMFUNCAO}		return T_FIMFUNCAO;          
{T_FIMPARA}		return T_FIMPARA;           
{T_FIMPROCEDIMENTO}	return T_FIMPROCEDIMENTO;  
{T_FIMREPITA}		return T_FIMREPITA;       
{T_FIMSE}		return T_FIMSE;          
{T_FUNCAO}		return T_FUNCAO;       
{T_GRAUPRAD}		return T_GRAUPRAD       
{T_INICIO}		return T_INICIO;      
{T_INT}			return T_INT;
{T_INTEIRO}		return T_INTEIRO;  
{T_INTERROMPA}		return T_INTERROMPA;
{T_LEIA}		return T_LEIA;     
{T_LIMPATELA}		return T_LIMPATELA; 
{T_LITERAL}		return T_LITERAL;  
{T_LOG}			return T_LOG;
{T_LOGICO}		return T_LOGICO;  
{T_MAIUSC}		return T_MAIUSC; 
{T_MENSAGEM}		return T_MENSAGEM;
{T_MINUSC}		return T_MINUSC; 
{T_NUMPCARAC}		return T_NUMPCARAC;
{T_NUMERICO}		return T_NUMERICO; 
{T_OUTROCASO}		return T_OUTROCASO;
{T_PARA}		return T_PARA;     
{T_PASSO}		return T_PASSO;                 
{T_PAUSA}		return T_PAUSA;                 
{T_PI}			return T_PI;                    
{T_POS}			return T_POS;
{T_PROCEDIMENTO}	return T_PROCEDIMENTO;
{T_QUAD}		return T_QUAD;
{T_RADPGRAU}		return T_RADPGRAU;
{T_RAIZQ}		return T_RAIZQ;
{T_RAND}		return T_RAND;
{T_RANDI}		return T_RANDI;
{T_REAL}		return T_REAL;
{T_REPITA}		return T_REPITA;
{T_RETONRE}		return T_RETORNE;
{T_SE}			return T_SE;
{T_SEN}			return T_SEN;
{T_SENAO}		return T_SENAO;
{T_TAN}			return T_TAN;
{T_TIMER}		return T_TIMER;
{T_VAR}			return T_VAR;
{T_VETOR}		return T_VETOR;
{T_VERDADEIRO}		return T_VERDADEIRO;
{T_COMENTARIO_UL}	return T_COMENTARIO_UL; 
{T_COMENTARIO_ML}	return T_COMENTARIO_ML; 
"+"                 	return T_OPERADOR_SOMA;
"-"                 	return T_OPERADOR_SUBTRACAO;
"*"                 	return T_OPERADOR_MULTIPLICACAO;
"/"                 	return T_OPERADOR_DIVISAO;
"\\"                	return T_OPERADOR_DIVISAO_INT;
"\^"                	return T_OPERADOR_EXPONENCIACAO;
"%"                 	return T_OPERADOR_DIVISAO_RESTO;
{T_MOD}			return T_OPERADOR_DIVISAO_RESTO;
"="                 	return T_OPERADOR_IGUAL;
"<>"                	return T_OPERADOR_DIFERENTE;
"<"                 	return T_OPERADOR_MENOR;
">"                 	return T_OPERADOR_MAIOR;
"<="               	return T_OPERADOR_MENOR_IGUAL;
">="                	return T_OPERADOR_MAIOR_IGUAL;
"("                 	return T_PARENTESE_ESQ;
")"                 	return T_PARENTESE_DIR;
"["                 	return T_COLCHETE_ESQ;
"]"                 	return T_COLCHETE_DIR;
"\.\."                 	return T_VETOR_INTERVALO;
"<-"                	return T_OPERADOR_ATRIBUICAO;
","			return T_IDENT_SEPARADOR;
";"			return T_TIPO_ATRIBUIDOR;
{T_NUMERO_INTEIRO}	return T_NUMERO_INTEIRO;
{T_NUMERO_REAL}		return T_NUMERO_REAL;
{T_E}			return T_OP_LOGICO_E;}
{T_XOU}			return T_OP_LOGICO_XOU;}
{T_NAO}			return T_OP_LOGICO_NAO;}
{T_OU}			return T_OP_LOGICO_OU;}

{T_IDENTIFICADOR}	return T_IDENTIFICADOR;
{T_BRANCO}		{}
\n			return T_FIM_COMANANDO;
{T_INVALIDO}		return T_INVALIDO;
.			return ERRO;
