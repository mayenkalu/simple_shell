#include "main.h"

/**
 * _atoi - converts an integer string to an integer
 * @str: string pointer
 *
 * Return: converted integer or -1 on error.
 * If a letter is present in the string, -1 is returned
*/
int _atoi(char *str)
{
	int len;
	int num = 0;
	int i = 0;

	if (!str)
		return (-1);

	len = _strlen(str);

	for (i = (len - 1); i >= 0; i--)
	{
		if (*str < 48 || *str > 57)
			return (-1);

		num += (_pow(10, i) * (*str - '0'));

		str++;
	}

	return (num);
}
