#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long a = 1, b = 2, t;
	int i;

	for (i = 1; i <= 50; i++)
	{
		printf("%lu", a);
		if (i != 50)
			printf(", ");
		t = a + b;
		a = b;
		b = t;
	}
	printf("\n");
	return (0);
}
