%{
#define YYSTYPE double
#include "sql.tab.h"
#include <stdlib.h>
%}

T_BRANCO		[ \t\r]+
T_SELECT		(S|s)(E|e)(L|l)(E|e)(C|c)(T|T)	
T_FROM			(F|f)(R|r)(O|o)(M|m)
T_WHERE			(W|w)(H|h)(E|e)(R|r)(E|e)
T_AND                   (A|a)(N|n)(D|d)
T_OR                    (O|o)(R|r)
T_NOT                   (N|n)(O|o)(T|t)
T_ASC			(A|a)(S|s)(C|c)
T_DESC		        (D|d)(E|e)(S|s)(C|c)
T_AS                    (A|a)(S|s) 
T_ORDER_BY		(O|o)(R|r)(D|e)(R|r){T_BRANCO}(B|b)(Y|y)
T_NOME			[A-Za-z][A-Za-z0-9_]*
T_DIGITO		[0-9]
T_PARAMETRO_INTEIRO	{T_DIGITO}+
T_PARAMETRO_REAL	{T_PARAMETRO_INTEIRO}("."{T_PARAMETRO_INTEIRO}})?
T_PARAMETRO_STRING	\".*\"

%%

{T_BRANCO} { }
{T_SELECT}		return SELECT;
{T_FROM}		return FROM;
{T_WHERE}		return WHERE;
{T_AND}                 return AND;
{T_OR}                  return OR;
{T_ORDER_BY}		return ORDER_BY;
{T_NOME}		return NOME;
{T_DIGITO}		return DIGITO;
{T_PARAMETRO_INTEIRO}	return INTEIRO;
{T_PARAMETRO_REAL}	return REAL;
{T_PARAMETRO_STRING}	return STRING;
"*"			return ASTERISCO;
","			return IDENT_SEPARADOR;
"("			return PARENTESE_ESQ;
")"			return PARENTESE_DIR;
"="                     return IGUAL;
"<>"			return DIFERENTE;
"<"			return MENOR;
"<="			return MENOR_IGUAL;
">"			return MAIOR;
">="			return MAIOR_IGUAL;
"\n" 			return END;
