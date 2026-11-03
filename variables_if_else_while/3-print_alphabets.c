#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase then uppercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c;

	c = 97;
	while (c <= 122)
	{
		putchar(c);
		c++;
	}
	c = 65;
	while (c <= 90)
	{
		putchar(c);
		c++;
	}
	putchar(10);
	return (0);
}
