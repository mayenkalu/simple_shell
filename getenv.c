#include "main.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * _getenv - gets the value of an environment variable
 * @var: name of environment variable
 *
 * Return: malloc'd string containing value of the variable
 * or NULL on error and if the environment variable doesn't exist
*/
char *_getenv(char *var)
{
	int i = 0, len;
	char *str, **env;

	env = __environ;

	if (!var)
		return (NULL);

	while (env[i])
	{
		len = _strlen(var);

		/* the environment varible exists */
		if (_strncmp(var, env[i], len) == 0)
		{
			/*
			* Copy variable value to new malloc'd memory,
			* copy only after the = sign e.g PATH=WIE -> WIE
			 */
			str = _strdup(&env[i][len + 1]);

			if (!str)
				return (NULL);

			return (str);
		}
		i++;
	}

	return (NULL);
}
