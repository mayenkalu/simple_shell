#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * _puts - prints string to standard output
 * @s: string pointers
 *
 * Return: void
*/
void _puts(char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}
}
