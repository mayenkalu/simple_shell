#include "main.h"

/**
 * reverse_string - reverses a string
 * @s: string pointer
 *
 * Return: void
*/
void reverse_string(char *s)
{
	int i, len;
	char temp;

	len = _strlen(s) - 1;


	for (i = 0; i <= (len / 2); i++)
	{
		temp = s[len - i];

		s[len - i] = s[i];

		s[i] = temp;
	}
}
