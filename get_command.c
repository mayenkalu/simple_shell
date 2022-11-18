#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"


/**
 * get_command - checks if a command exists
 * @command: a malloc'd string pointer representing command
 *
 * Return: pointer to original command string if command
 * exists without /bin/ prefix,
 * a malloc'd string if prefix was needed otherwise NULL
*/
char *get_command(char *command)
{
	struct stat st;
	char *bin_command = prefix("/bin/", command);
	char *custom_command = prefix("./programs/", command);
	char *command_copy = _strdup(command);

	if (!bin_command || !custom_command || !command_copy)
		return (NULL);

	/* Path exists */
	if (lstat(command_copy, &st) == 0)
	{
		free(bin_command);
		free(custom_command);
		return (command_copy);
	}

	free(command_copy);

	if (lstat(bin_command, &st) == 0)
	{
		free(custom_command);
		return (bin_command);
	}

	free(bin_command);

	if (lstat(custom_command, &st) == 0)
		return (custom_command);

	free(custom_command);

	return (NULL);
}
