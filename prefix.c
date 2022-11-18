#include "main.h"
#include <stdlib.h>

/**
 * prefix  - returns a malloc'd string prefixed with prefix
 * @prefix: string pointer to prefix
 * @str: string
 *
 * Return: A malloc'd string with the prefixed string;
 */
char *prefix(char *prefix, char *str)
{
	int pref_len, str_len;
	char *prefixed_string = NULL;

	if (!prefix || !str)
		return (NULL);

	pref_len = _strlen(prefix);
	str_len = _strlen(str);

	prefixed_string = malloc(sizeof(char) * (pref_len + str_len + 1));

	if (!prefixed_string)
		return (NULL);

	/* Copy prefix into prefixed string*/
	_strcpy(prefixed_string, prefix);

	/* Concatinate string with prefixed string*/
	_strcat(prefixed_string, str);

	return (prefixed_string);
}
