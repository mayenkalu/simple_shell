#include "main.h"
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void fork_n_execute(char **args, char *env[], char *argv[], int *status);
void handle_sigint(int sig);

/**
 * main - entry point
 * @argc: numbers of command line arguments
 * @argv: array of command line arguments
 * @env: environment variables
 *
 * Return: Always 0
*/
int main(__attribute__((unused)) int argc, char *argv[], char *env[])
{
	char *input = NULL, *cmd;
	char **args;
	int status = 0;

	signal(SIGINT, handle_sigint);
	while (*(input = prompt()))
	{
		args = split(input);
		free(input);


		/* Skip current execution if the no command was passed */
		if (!args)
			continue;

		/* Handle replacements */
		replace_variables(args, status);

		/* Handle built in commands */
		if (handle_builtins(args, argv[0]))
		{
			free_split(args);
			continue;
		}

		/* Get full command path e.g ls -> /bin/ls */
		cmd = get_command(args[0]);

		if (!cmd)
		{
			/* If command doesn't exist skip the current execute */
			_puts("Error\n");
			free_split(args);
			continue;
		}

		/* Free previous command before overwriting it*/
		free(args[0]);
		args[0] = cmd;

		/* Create a child process and execute the command in the child process*/
		fork_n_execute(args, env, argv, &status);

		/* Free all args */
		free_split(args);
	}

	free(input);
	return (0);
}

/**
 * fork_n_execute - creates a child process of the main process and executes a
 * command in it
 * @args: An array containing the command and the command arguments where
 * args[0] is the command itself
 * @env: An array of the environment variables
 * @argv: The array arguments passed into the executing program
 * @status: an integer pointer where the status of the
 * executed process is stored
 *
 * Return: void
*/
void fork_n_execute(char **args, char *env[], char *argv[], int *status)
{
	pid_t child;

	child = fork();

	/* Execute command only if the current process is the child process*/
	if (child == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(argv[0]);
			exit(1);
		}
	}
	else
	{
		/* Wait for child process to exit before continuing*/
		wait(status);
	}

}

/**
 * handle_sigint - handler for signal
 * @sig: signal
 *
 * Return: void
*/
void handle_sigint(int sig)
{
	(void) sig;

	write(STDERR_FILENO, "\n$", 2);
}
