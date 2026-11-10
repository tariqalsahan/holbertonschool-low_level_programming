#include "main.h"

/**
 * puts_half - prints the second half of a string, followed by a new line
 * @str: the string to print
 *
 * Description: if the length is odd, prints the last n characters,
 * where n = (length + 1) / 2
 * Return: void
 */
void puts_half(char *str)
{
	int len;
	int i;

	len = 0;
	while (str[len] != '\0')
		len++;

	for (i = len - (len + 1) / 2; i < len; i++)
		_putchar(str[i]);
	_putchar('\n');
}
