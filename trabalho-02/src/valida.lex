%{
/* Exemplo de uso do Flex */
%}
EMAIL		[a-zA-Z][a-zA-Z0-9\.\-\_]+@([a-zA-Z][a-zA-Z]+\.)+[a-zA-Z][a-zA-Z]+
FIM_LINHA	[\n]
%%

{EMAIL}			printf("%s -> Email Válido\n", yytext);
.			printf("%s -> Email Inválido\n", yytext);
%%
main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf ("Missing input file\n");exit(-1);
	}
	yyin = fopen(argv[1], "r" );
	yylex();
}
