#include "main.h"

/**
 * _pow - raises x to the power of y
 * @x: base number
 * @y: power
 *
 * Return: x to the power of y
 */

int _pow(int x, int y)
{
	if (y == 0)
	{
		return (1);
	}
	else if (y < 0)
	{
		return (-1);
	}

	return (x * _pow(x, y - 1));
}
