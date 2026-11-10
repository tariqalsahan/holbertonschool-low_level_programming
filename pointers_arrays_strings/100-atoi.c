#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Description: every '-' before the first digit flips the sign.
 * The number is built as a negative value so that the most
 * negative int can be stored without signed overflow.
 * Return: the converted integer, or 0 if there is no number
 */
int _atoi(char *s)
{
	int sign;
	int result;

	sign = 1;
	result = 0;

	while (*s != '\0' && (*s < '0' || *s > '9'))
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 - (*s - '0');
		s++;
	}

	if (sign > 0)
		result = -result;

	return (result);
}
