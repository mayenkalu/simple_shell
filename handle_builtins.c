include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * handle_builtins - handles built in functions like env, cd and exit
 * @args: array of command arguments
 * @program_name: name of executing program i.e argv[0]
 *
 * Return: 1 if a built in function was matched else 0
*/
int handle_builtins(char **args, char *program_name)
{
	void (*handler)(char **);

	if (!args || !program_name)
		return (0);

	handler = get_builtin_func(args[0]);

	if (!handler)
		return (0);

	handler(args);

	return (1);
}
