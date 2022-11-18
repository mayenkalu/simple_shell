#include <stdlib.h>
#include "main.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * replace_variables - replaces variables in a shell program denoted by $
 * @args: array strings containing the command and its arguments
 * @status: exit status of previously executed program
 *
 * Return:
*/
void replace_variables(char **args, int status)
{
	int i = 1;
	char *str;

	if (!args)
		return;

	while (args[i])
	{
		if (args[i][0] == '$' && args[i][1])
		{
			switch (args[i][1])
			{
			case '$':
				str = _itoa((int) getpid());
				break;

			case '?':
				str = _itoa(WEXITSTATUS(status));
				break;

			default:
				str = _getenv(&args[i][1]);
				break;
			}

			free(args[i]);

			if (str)
				args[i] = str;
			else
				args[i] = _strdup("");
		}
		i++;
	}

}
