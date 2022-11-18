#include <unistd.h>
#include <stdlib.h>

/**
 * _strlen - gets lenght of string
 * @s: character
 *
 * Return: lenth of string
*/
int _strlen(char *s)
{
	int count = 0;

	while (*s)
	{
		count++;
		s++;
	}

	return (count);
}
