#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * cd_handler - handles the shell cd command
 * @args: array of command and arguments
 *
 * Return: void
*/
void cd_handler(char **args)
{
	char *path = NULL;
	char *tmp = NULL;

	path = args[1];

	if (!path || (_strcmp(path, "~") == 0))
		tmp = path = _getenv("HOME");

	if (chdir(path) != 0)
		perror("./shell");
	else
	{
		path = getcwd(NULL, 0);
		/*setenv("PWD", path, 1);*/
		free(path);
	}

	free(tmp);
}
