#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[]) {
	FILE *arquivo; 
	char caracter;
	int estado = 0; //Vai armazenar os estados correntes
	int i;

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

	//Percorre todas as linhas do arquivo
	caracter = getc(arquivo);
	while(caracter != EOF)
	{
		switch(caracter){
			case 'l': printf("achou l \n");
			break;
		}
		caracter = getc(arquivo);
	}

	fclose(arquivo);
	
	return(1);
} 
