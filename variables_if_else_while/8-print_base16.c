#include <stdio.h>

/**
 * main - Prints all numbers of base 16 in lowercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n = 0;

	while (n < 16)
	{
		if (n < 10)
			putchar(n + 48);
		else
			putchar(n + 87);
		n++;
	}
	putchar(10);
	return (0);
}
