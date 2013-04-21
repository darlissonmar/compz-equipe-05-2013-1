#include <stdio.h>
#include <stdlib.h>

#define ESTADO_FINAL 0

int main( int argc, char *argv[]) {
	FILE *arquivo; //Ponteiro para o arquivo de entrada
	char caracter; //Vai armazenar o caracter corrente
	char email; //Vai armazenar o conjunto de caracteres de uma linha que formará o email escrito na saída
	int estado = 0; //Vai armazenar os estados correntes


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

	//Percorre todas os caracteres
	caracter = getc(arquivo);
	while(caracter != EOF)
	{
		switch(estado)
		{
			case 0:
			switch(caracter)
			{
				case 'a': estado = 0; break;
				case 'b': estado = 0; break;
				case 'c': estado = 0; break;
				case 'd': estado = 0; break;
				case 'e': estado = 0; break;
				case 'f': estado = 0; break;
				case 'g': estado = 0; break;
				case 'h': estado = 0; break;
				case 'i': estado = 0; break;
				case 'j': estado = 0; break;
				case 'k': estado = 0; break;
				case 'l': estado = 0; break;
				case 'm': estado = 0; break;
				case 'n': estado = 0; break;
				case 'o': estado = 0; break;
				case 'p': estado = 0; break;
				case 'q': estado = 0; break;
				case 'r': estado = 0; break;
				case 's': estado = 0; break;
				case 't': estado = 0; break;
				case 'u': estado = 0; break;
				case 'v': estado = 0; break;
				case 'x': estado = 0; break;
				case 'y': estado = 0; break;
				case 'w': estado = 0; break;
				case 'z': estado = 0; break;
                case '\n': break;
				default: estado = -1; break;

			}
			break;
		}
        if (caracter == '\n'){
            if (estado == ESTADO_FINAL)
                printf("Email Valido\n", email);
            else
                printf("Email Invalido\n", email);

            estado = 0;
        }

        caracter = getc(arquivo);

	}

	fclose(arquivo);

	return(1);
}
