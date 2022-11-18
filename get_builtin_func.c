#include "main.h"
#include <stddef.h>

/**
 * get_builtin_func - returns a builtin function that matches the shell command
 * @command: string pointer to a shell command
 *
 * Return: a function pointer to a function that returns void and
 * takes in an array as an argument or NULL on error
*/
void (*get_builtin_func(char *command))(char **)
{
	int i = 0;
	builtin_t builtins[] = {
		{"env", env_handler},
		{"cd", cd_handler},
		{"exit", exit_handler},
		{NULL, NULL}
	};

	if (!command)
		return (NULL);

	while (builtins[i].command)
	{
		if (_strcmp(command, builtins[i].command) == 0)
			return (builtins[i].handler);

		i++;
	}

	return (NULL);
}
