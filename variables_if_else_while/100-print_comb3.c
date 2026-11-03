#include <stdio.h>

/**
 * main - Prints all possible different combinations of two digits
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0, j;

	while (i < 9)
	{
		j = i + 1;
		while (j < 10)
		{
			putchar(i + 48);
			putchar(j + 48);
			if (i != 8)
			{
				putchar(44);
				putchar(32);
			}
			j++;
		}
		i++;
	}
	putchar(10);
	return (0);
}
