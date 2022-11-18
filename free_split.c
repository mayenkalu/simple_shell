#include "main.h"
#include <stdlib.h>

/**
 * free_split - frees and array created with the split function
 * @string: array of string pointers
 *
 * Return: void
 */
void free_split(char **string)
{
	int i = 0;

	while (string[i])
	{
		free(string[i]);
		i++;
	}

	free(string);
}
