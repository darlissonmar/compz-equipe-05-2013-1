#include <stdio.h>

void print_part(int *mypart, int n)
{
	int print, subset, i, j;	
	
	subset = 1;
	for (i = 0; i < n; i++)
	{
		if (mypart[i] > subset)
		{
			subset = mypart[i];
		}
	}   		

	for (j = subset; j >= 1; j--)
	{
		print = 0;						
		printf("{");						
		for (i = 0; i < n; i++)
		{				
			if (mypart[i] == j)
			{						
				print++;			
				if(print >= 2)
				{		
					printf(",%d", i + 1);		
				} 
				else
				{			
					printf("%d", i + 1);
				}
			}
		}
		printf("}");

		if(j >= 1)
		{
			printf("\t");
		}
	}

	printf("\n");
}

int has_part(int *mypart, int n)
{	
	int i, j;
	
	i = 0;
	mypart[i]++;
	mypart[n] = 1;

	for (j = i + 1; j < n - 1; ++j)
	{
		if (mypart[j] > mypart[n])
			mypart[n] = mypart[j];
	}

	if ( mypart[0] == n + 1 )
		return 0;

	while ((mypart[i] > mypart[n] + 1)) 
	{
		mypart[i] = 1;
		i++;
		mypart[i]++;
		mypart[n] = 1;
	
		j = 0;
		for (j = i + 1; j < n - 1; ++j)
		{
			if (mypart[j] > mypart[n])
			{
				mypart[n] = mypart[j];			
			}
		}
	}

	return 1;
}

void main(int argc, char *argv[])
{  
	int n = atoi(argv[1]);
	int mypart[n];
	
	int i;	
	for (i = 0; i < n; i++)
	{
		mypart[i] = 1;
	}
	print_part(mypart, n);
	
	while (has_part(mypart, n))
	{
		print_part(mypart, n);
	}
}
