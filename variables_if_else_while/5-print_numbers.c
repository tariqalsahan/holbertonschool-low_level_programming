#include <stdio.h>

/**
 * main - Prints all single digit numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n = 0;

	while (n < 10)
	{
		putchar(n + 48);
		n++;
	}
	putchar(10);
	return (0);
}
