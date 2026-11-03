#include "main.h"

/**
 * print_num - Prints an integer using _putchar
 * @n: The number to print
 */
void print_num(int n)
{
	unsigned int u;

	if (n < 0)
	{
		_putchar('-');
		u = -n;
	}
	else
	{
		u = n;
	}
	if (u / 10)
		print_num(u / 10);
	_putchar(u % 10 + '0');
}

/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: The starting number
 */
void print_to_98(int n)
{
	while (n != 98)
	{
		print_num(n);
		_putchar(',');
		_putchar(' ');
		if (n < 98)
			n++;
		else
			n--;
	}
	print_num(98);
	_putchar('\n');
}
