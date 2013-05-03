%{
/* Exemplo de uso do Flex */
%}
EMAIL		[a-zA-Z][a-zA-Z0-9\.\-\_]+@([a-zA-Z][a-zA-Z]+\.)+[a-zA-Z][a-zA-Z]+
%%

{EMAIL}	printf("%s OK\n", yytext);
.			printf("%s NOK\n", yytext);
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
