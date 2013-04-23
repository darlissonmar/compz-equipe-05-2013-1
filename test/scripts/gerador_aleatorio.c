#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUMERO_MAX 999999 // < 10^6
#define NUMERO_MIN 1
#define NUMERO_TOTAL 100000 // 10^5


int RandomInteger(int low, int high);

int main(void)
{
	int i;
	srand(time(NULL));

	for( i= 0; i < NUMERO_TOTAL; i++)
	{
		printf("%d\n", RandomInteger(NUMERO_MIN, NUMERO_MAX));
	}


	return 0;
}

// A função RandomInteger devolve um inteiro
// aleatório entre low e high inclusive,
// ou seja, no intervalo fechado low..high.
// Vamos supor que 0 <= low <= high < INT_MAX.
// O código foi copiado da biblioteca random
// de Eric Roberts.

int RandomInteger( int low, int high)
{
    int k;
    double d;
    d = (double) rand( ) / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}
