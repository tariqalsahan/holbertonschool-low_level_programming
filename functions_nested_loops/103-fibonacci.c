#include <stdio.h>

/**
 * main - Prints the sum of the even-valued Fibonacci terms
 * not exceeding 4,000,000
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long a = 1, b = 2, t, sum = 0;

	while (a <= 4000000)
	{
		if (a % 2 == 0)
			sum += a;
		t = a + b;
		a = b;
		b = t;
	}
	printf("%lu\n", sum);
	return (0);
}
