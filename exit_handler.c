#include "main.h"
#include <stdlib.h>

/**
 * exit_handler - handles the shell exit command
 * @args: array of command and arguments
 *
 * Return: void
*/
void exit_handler(char **args)
{
	int exitCode = 0;

	if (!args)
		return;

	exitCode = _atoi(args[1]);

	free_split(args);

	if (exitCode == -1)
		exit(0);

	exit(exitCode);
}
