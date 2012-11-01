#include <stdio.h>
#include <stdlib.h>

// Function to calculate all primes less than or equal to top
// using the sieve of Eratosthenes (sieve of Atkin will come later),
// and print them out with breaker characters per row

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

// Main function, takes two command line parameters. The first is the top
// uint in the above function, the second is its breaker param. Super simple stuff.

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
