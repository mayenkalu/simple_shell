#include "main.h"
#include <string.h>

/**
 * _strcat - concatenate two string
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to destination string
 */

char *_strcat(char *dest, char *src)
{
	int start = _strlen(dest);
	int i = 0;

	while (src[i] != '\0')
	{
		dest[start + i] = src[i];
		i++;
	}
	dest[start + i] = src[i];

	return (dest);
}
