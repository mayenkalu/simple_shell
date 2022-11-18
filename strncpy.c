#include "main.h"

/**
 * _strncpy - copy n bytes from source string to
 * destination string
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to be concatenated
 *
 * Return: pointer string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
