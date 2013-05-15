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
T_ORDER_BY		(O|o)(R|r)(D|e)(R|r){T_BRANCO}(B|b)(Y|y)
T_NOME			[A-Za-z][A-Za-z0-9_]*
T_DIGITO		[0-9]
T_PARAMETRO_INTEIRO	{T_DIGITO}+
T_PARAMETRO_REAL	{T_PARAMETRO_INTEIRO}("."{T_PARAMETRO_INTEIRO}})?
T_PARAMETRO_STRING	\".*\"

%%

{T_BRANCO} { }
{T_SELECT}		return T_SELECT;
{T_FROM}		return T_FROM;
{T_WHERE}		return T_WHERE;
{T_ORDER_BY}		return T_ORDER_BY;
{T_NOME}		return T_NOME;
{T_DIGITO}		return T_DIGITO;
{T_PARAMETRO_INTEIRO}	return T_PARAMETRO;
{T_PARAMETRO_REAL}	return T_PARAMETRO;
{T_PARAMETRO_STRING}	return T_PARAMETRO;
"*"			return T_TODOS;
","			return T_IDENT_SEPARADOR;
"("			return T_PARENTESE_ESQ;
")"			return T_PARENTESE_DIR;
"\n" 			return T_END;
