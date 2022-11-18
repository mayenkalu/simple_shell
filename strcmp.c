#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 1, -1 or 0
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] || s2[i])
	{
		if (!s1[i])
		{
			return (-1);
		}
		else if (!s2[i])
		{
			return (1);
		}
		else
		{
			if (s1[i] > s2[i])
			{
				return (1);
			}
			else if (s1[i] < s2[i])
			{
				return (-1);
			}
			else
			{
				;
			}
		}

		i++;

	}

	return (0);
}
