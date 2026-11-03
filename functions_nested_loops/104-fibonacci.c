#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long a1 = 0, a2 = 1, b1 = 0, b2 = 2, t1, t2;
	unsigned long base = 10000000000UL;
	int i;

	for (i = 1; i <= 98; i++)
	{
		if (a1)
			printf("%lu%010lu", a1, a2);
		else
			printf("%lu", a2);
		if (i != 98)
			printf(", ");
		t1 = a1 + b1;
		t2 = a2 + b2;
		if (t2 >= base)
		{
			t1++;
			t2 -= base;
		}
		a1 = b1;
		a2 = b2;
		b1 = t1;
		b2 = t2;
	}
	printf("\n");
	return (0);
}
