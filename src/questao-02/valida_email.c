#include <stdio.h>
#include <stdlib.h>



int main( int argc, char *argv[]) {
	FILE *arquivo; 

	//Verifica se o argumento referente ao diretório do arquivo foi passado
	if(argc < 2)
	{
		printf("\nErro: Digite o nome do arquivo !!!\n");	
		exit(1);
	}

	//Verifica se o diretório do arquivo existe
	if((arquivo = fopen(argv[1],"r")) == NULL)
	{
		printf("Erro ao abrir arquivo!!!\n");
		exit(1);
	}
	
	return(1);
} 
