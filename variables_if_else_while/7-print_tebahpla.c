#include <stdio.h>

/**
 * main - Prints the alphabet in reverse
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c = 122;

	while (c >= 97)
	{
		putchar(c);
		c--;
	}
	putchar(10);
	return (0);
}
