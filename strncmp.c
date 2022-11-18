#include "main.h"
/**
 * _strncmp - compares first n bytes of two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to compare
 *
 * Return: 0 if n bytes of strings match, otherwise -1
 */
int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;

	/* s1 or s2 is NULL */
	if (!s1 || !s2)
		return (-1);

	while ((i < n) && (s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return (-1);

		i++;
	}

	/* less than n bytes were compared */
	if (i != n)
		return (-1);

	return (0);
}
