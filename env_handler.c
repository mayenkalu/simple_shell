#include "main.h"
#include <unistd.h>

/**
 * env_handler - handles the shell env command
 * @args: array of command and arguments
 *
 * Return: void
*/
void env_handler(char **args)
{
	if (!args)
		return;

	print_array(__environ);
}
