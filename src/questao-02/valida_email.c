#include <stdio.h>
#include <stdlib.h>

#define ESTADO_FINAL 5

/**
    Algoritmo desenvolvido para a disciplina de Compiladores do curso de Engenharia da Computação da Universidade do Estado do Amazonas
    Delegado da Questão: Williams Araújo

    O Programa tem como objetivo validar emails utilizando a técnica de automatos finitos, a representação gráfica do automato se encontra
    na pasta [docs] referente a [questao-2]

    O programa recebe como argumento de entrada um arquivo .txt contendo em cada linha o email a ser verificado.

    Para um endereço de email ser válido ele deve:
    1) Começar obrigadoriamente com uma letra
    2) Em seguida pode ter (letra, número, -, _ ou .) até que o próximo caracter seja o (@)
    3) Após o (@) o próximo caractere deve ser obrigatoriamente uma letra
    4) Em seguida pode ter (letra, número) até que o próximo caracter seja o (.)
    5) Após o (.) devemos ter apenas letras
    6) Se outro (.) for encontrado, devemos ter pelo menos uma letra em seguida

    Ex: williams@gmail.com -> Válido
        joao.@gmail.com -> Válido
        _marcos@hotmail.com -> Inválido
        ana@@hotmail.com -> Inválido
        luana@gmail.edu.com.br -> Válido (Podemos ter quantas extensões de domínio forem necessárias)
        darlisson@yahoo. -> Inválido
        leandro@9ag.com -> Inválido
        leandro@ag9.com -> Válido
        lendro@ag9.c1m - Inválido
**
**/

int main( int argc, char *argv[]) {
	FILE *arquivo; //Ponteiro para o arquivo de entrada
	char caracter; //Vai armazenar o caracter corrente
	char email; //Vai armazenar o conjunto de caracteres de uma linha que formará o email escrito na saída
	int estado = 0; //Vai armazenar os estados correntes (-1: indica estado morto)


	//Verifica se o argumento referente ao diretório do arquivo foi passado
	if(argc < 2)
	{
		printf("\nErro: Digite o nome do arquivo !!!\n");
		exit(1);
	}

	//Verifica se o diretório do arquivo existe
	if((arquivo = fopen(argv[1],"r")) == NULL)
	{
		printf("Erro ao abrir arquivo %s !!!\n", argv[1]);
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
				case 'a': estado = 1; break;
				case 'b': estado = 1; break;
				case 'c': estado = 1; break;
				case 'd': estado = 1; break;
				case 'e': estado = 1; break;
				case 'f': estado = 1; break;
				case 'g': estado = 1; break;
				case 'h': estado = 1; break;
				case 'i': estado = 1; break;
				case 'j': estado = 1; break;
				case 'k': estado = 1; break;
				case 'l': estado = 1; break;
				case 'm': estado = 1; break;
				case 'n': estado = 1; break;
				case 'o': estado = 1; break;
				case 'p': estado = 1; break;
				case 'q': estado = 1; break;
				case 'r': estado = 1; break;
				case 's': estado = 1; break;
				case 't': estado = 1; break;
				case 'u': estado = 1; break;
				case 'v': estado = 1; break;
				case 'x': estado = 1; break;
				case 'y': estado = 1; break;
				case 'w': estado = 1; break;
				case 'z': estado = 1; break;
    				case '\n': estado = -1; break;
				default: estado = -1; break;
			}
			break;
			case 1:
			switch(caracter)
			{
				case 'a': estado = 1; break;
				case 'b': estado = 1; break;
				case 'c': estado = 1; break;
				case 'd': estado = 1; break;
				case 'e': estado = 1; break;
				case 'f': estado = 1; break;
				case 'g': estado = 1; break;
				case 'h': estado = 1; break;
				case 'i': estado = 1; break;
				case 'j': estado = 1; break;
				case 'k': estado = 1; break;
				case 'l': estado = 1; break;
				case 'm': estado = 1; break;
				case 'n': estado = 1; break;
				case 'o': estado = 1; break;
				case 'p': estado = 1; break;
				case 'q': estado = 1; break;
				case 'r': estado = 1; break;
				case 's': estado = 1; break;
				case 't': estado = 1; break;
				case 'u': estado = 1; break;
				case 'v': estado = 1; break;
				case 'x': estado = 1; break;
				case 'y': estado = 1; break;
				case 'w': estado = 1; break;
				case 'z': estado = 1; break;
				case '.': estado = 1; break;
				case '-': estado = 1; break;
				case '_': estado = 1; break;
				case '0': estado = 1; break;
				case '1': estado = 1; break;
				case '2': estado = 1; break;
				case '3': estado = 1; break;
				case '4': estado = 1; break;
				case '5': estado = 1; break;
				case '6': estado = 1; break;
				case '7': estado = 1; break;
				case '8': estado = 1; break;
				case '9': estado = 1; break;
				case '@': estado = 2; break;

                		case '\n': estado = -1; break;
				default: estado = -1; break;
			}
			break;
			case 2:
			switch(caracter)
			{
                		case 'a': estado = 3; break;
				case 'b': estado = 3; break;
				case 'c': estado = 3; break;
				case 'd': estado = 3; break;
				case 'e': estado = 3; break;
				case 'f': estado = 3; break;
				case 'g': estado = 3; break;
				case 'h': estado = 3; break;
				case 'i': estado = 3; break;
				case 'j': estado = 3; break;
				case 'k': estado = 3; break;
				case 'l': estado = 3; break;
				case 'm': estado = 3; break;
				case 'n': estado = 3; break;
				case 'o': estado = 3; break;
				case 'p': estado = 3; break;
				case 'q': estado = 3; break;
				case 'r': estado = 3; break;
				case 's': estado = 3; break;
				case 't': estado = 3; break;
				case 'u': estado = 3; break;
				case 'v': estado = 3; break;
				case 'x': estado = 3; break;
				case 'y': estado = 3; break;
				case 'w': estado = 3; break;
				case 'z': estado = 3; break;

                		case '\n': estado = -1; break;
                		default: estado = -1; break;
			}
			break;
			case 3:
			switch(caracter)
			{
               			case 'a': estado = 3; break;
				case 'b': estado = 3; break;
				case 'c': estado = 3; break;
				case 'd': estado = 3; break;
				case 'e': estado = 3; break;
				case 'f': estado = 3; break;
				case 'g': estado = 3; break;
				case 'h': estado = 3; break;
				case 'i': estado = 3; break;
				case 'j': estado = 3; break;
				case 'k': estado = 3; break;
				case 'l': estado = 3; break;
				case 'm': estado = 3; break;
				case 'n': estado = 3; break;
				case 'o': estado = 3; break;
				case 'p': estado = 3; break;
				case 'q': estado = 3; break;
				case 'r': estado = 3; break;
				case 's': estado = 3; break;
				case 't': estado = 3; break;
				case 'u': estado = 3; break;
				case 'v': estado = 3; break;
				case 'x': estado = 3; break;
				case 'y': estado = 3; break;
				case 'w': estado = 3; break;
				case 'z': estado = 3; break;
				case '0': estado = 3; break;
				case '1': estado = 3; break;
				case '2': estado = 3; break;
				case '3': estado = 3; break;
				case '4': estado = 3; break;
				case '5': estado = 3; break;
				case '6': estado = 3; break;
				case '7': estado = 3; break;
				case '8': estado = 3; break;
				case '9': estado = 3; break;
				case '.': estado = 4; break;

                		case '\n': estado = -1; break;
				default: estado = -1; break;
			}
			break;
			case 4:
			switch(caracter)
			{
                		case 'a': estado = 5; break;
				case 'b': estado = 5; break;
				case 'c': estado = 5; break;
				case 'd': estado = 5; break;
				case 'e': estado = 5; break;
				case 'f': estado = 5; break;
				case 'g': estado = 5; break;
				case 'h': estado = 5; break;
				case 'i': estado = 5; break;
				case 'j': estado = 5; break;
				case 'k': estado = 5; break;
				case 'l': estado = 5; break;
				case 'm': estado = 5; break;
				case 'n': estado = 5; break;
				case 'o': estado = 5; break;
				case 'p': estado = 5; break;
				case 'q': estado = 5; break;
				case 'r': estado = 5; break;
				case 's': estado = 5; break;
				case 't': estado = 5; break;
				case 'u': estado = 5; break;
				case 'v': estado = 5; break;
				case 'x': estado = 5; break;
				case 'y': estado = 5; break;
				case 'w': estado = 5; break;
				case 'z': estado = 5; break;

                		case '\n': estado = -1; break;
				default: estado = -1; break;
			}
			break;
			case 5:
			switch(caracter)
			{
                		case 'a': estado = 5; break;
				case 'b': estado = 5; break;
				case 'c': estado = 5; break;
				case 'd': estado = 5; break;
				case 'e': estado = 5; break;
				case 'f': estado = 5; break;
				case 'g': estado = 5; break;
				case 'h': estado = 5; break;
				case 'i': estado = 5; break;
				case 'j': estado = 5; break;
				case 'k': estado = 5; break;
				case 'l': estado = 5; break;
				case 'm': estado = 5; break;
				case 'n': estado = 5; break;
				case 'o': estado = 5; break;
				case 'p': estado = 5; break;
				case 'q': estado = 5; break;
				case 'r': estado = 5; break;
				case 's': estado = 5; break;
				case 't': estado = 5; break;
				case 'u': estado = 5; break;
				case 'v': estado = 5; break;
				case 'x': estado = 5; break;
				case 'y': estado = 5; break;
				case 'w': estado = 5; break;
				case 'z': estado = 5; break;
				case '.': estado = 6; break;

				case '\n': estado = 5; break;
				default: estado = -1; break;

			}
			break;
			case 6:
			switch(caracter)
			{
                		case 'a': estado = 5; break;
				case 'b': estado = 5; break;
				case 'c': estado = 5; break;
				case 'd': estado = 5; break;
				case 'e': estado = 5; break;
				case 'f': estado = 5; break;
				case 'g': estado = 5; break;
				case 'h': estado = 5; break;
				case 'i': estado = 5; break;
				case 'j': estado = 5; break;
				case 'k': estado = 5; break;
				case 'l': estado = 5; break;
				case 'm': estado = 5; break;
				case 'n': estado = 5; break;
				case 'o': estado = 5; break;
				case 'p': estado = 5; break;
				case 'q': estado = 5; break;
				case 'r': estado = 5; break;
				case 's': estado = 5; break;
				case 't': estado = 5; break;
				case 'u': estado = 5; break;
				case 'v': estado = 5; break;
				case 'x': estado = 5; break;
				case 'y': estado = 5; break;
				case 'w': estado = 5; break;
				case 'z': estado = 5; break;

				case '\n': estado = -1; break;
				default: estado = -1; break;
			}
			break;

		}
        if (caracter != '\n')
            putchar(caracter);

        if (caracter == '\n'){
            if (estado == ESTADO_FINAL)
                printf(" -> Email Valido\n", email);
            else
                printf(" -> Email Invalido\n", email);

            estado = 0;
        }

        caracter = getc(arquivo);

	}

	fclose(arquivo);

	return(1);
}
