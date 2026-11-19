#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates s1 and the first n bytes of s2
 * @s1: the first string (NULL is treated as an empty string)
 * @s2: the second string (NULL is treated as an empty string)
 * @n: the number of bytes of s2 to use
 *
 * Return: pointer to the newly allocated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *res;
	unsigned int len1, len2, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (len1 = 0; s1[len1] != '\0'; len1++)
		;
	for (len2 = 0; s2[len2] != '\0'; len2++)
		;

	if (n > len2)
		n = len2;

	res = malloc(sizeof(char) * (len1 + n + 1));
	if (res == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		res[i] = s1[i];
	for (j = 0; j < n; j++)
		res[i + j] = s2[j];
	res[i + j] = '\0';

	return (res);
}
