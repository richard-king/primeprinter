#include <stdio.h>
#include <stdlib.h>

// Function to calculate all primes less than or equal to top
// using the sieve of Eratosthenes (sieve of Atkin will come later),
// and print them out with breaker characters per row

int prpr(unsigned int top, unsigned int breaker)
{
	char *primes; // Every number is either true or false, so a simple char array will suffice
	unsigned i, j;

	primes = calloc(top+1, sizeof primes); // Get the array we need. Note that calloc sets them all to zero (false) -> true means composite number

	primes[0] = 1; // 0 is not prime - trivial
	primes[1] = 1; // 1 is not prime - definition of a prime number

	for(i = 2; i * i <= top; ++i) // Only need to go till we hit the square root of the largest value. Guaranteed positive numbers, so x * x < y is easier than x < root(y).
	{
		if(!primes[i]) // If we meet a prime
		{
			for(j = i * i; j <= top; j += i)
			{
				primes[j] = 1; // Set its multiples to be composite.
			}
		}
	}

	// Time to loop and print!

	for(i = 0; i <= top; ++i)
	{
		((i % breaker == 0) && (printf("\n")));
		!primes[i] ? printf("▒") : printf("▓");
	}

	free(primes); // Or else sploshins.
	
	printf("\n\n"); // Prettiness. Ish.

	return 0; // Hoorah!
}

// Main function, takes two command line parameters. The first is the top
// uint in the above function, the second is its breaker param. Super simple stuff.

int main(int argc, char* argv[])
{
	if(argc != 3) // You never know... Segfault...
	{
		printf("Usage: primeprinter top break"); // Got some splainin' to do
		return 1;
	}

	int a = atoi(argv[1]), b = atoi(argv[2]);
	prpr(a, b); // Let's do this!
	return 0;
}
