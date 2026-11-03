#include <stdio.h>

/**
 * main - Prints all single digit numbers separated by comma
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n = 0;

	while (n < 10)
	{
		putchar(n + 48);
		if (n < 9)
		{
			putchar(44);
			putchar(32);
		}
		n++;
	}
	putchar(10);
	return (0);
}
