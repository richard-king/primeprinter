#include <stdio.h>
#include <stdlib.h>

int prpr(unsigned int top, unsigned int breaker)
{
	char *primes;
	unsigned i, j;

	primes = calloc(top+1, sizeof primes);

	primes[0] = 1;
	primes[1] = 1;

	for(i = 2; i * i <= top; ++i)
	{
		if(!primes[i])
		{
			for(j = i * i; j <= top; j += i)
			{
				primes[j] = 1;
			}
		}
	}

	for(i = 0; i <= top; ++i)
	{
		((i % breaker == 0) && (printf("\n")));
		!primes[i] ? printf("▒") : printf("▓");
	}

	free(primes);
	
	printf("\n\n");

	return 0;
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("Usage: primeprinter top break");
		return 1;
	}

	int a = atoi(argv[1]), b = atoi(argv[2]);
	prpr(a, b);
	return 0;
}
