#include <stdio.h>

/**
 * main - Prints all possible combinations of two two-digit numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int a = 0, b;

	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			putchar(a / 10 + 48);
			putchar(a % 10 + 48);
			putchar(32);
			putchar(b / 10 + 48);
			putchar(b % 10 + 48);
			if (a != 98)
			{
				putchar(44);
				putchar(32);
			}
			b++;
		}
		a++;
	}
	putchar(10);
	return (0);
}
