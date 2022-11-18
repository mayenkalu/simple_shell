#include "main.h"

/**
 * _strcpy  - copys strings from src to dest
 * @src: source string
 * @dest: destination string
 *
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = src[i];
	return (dest);
}
