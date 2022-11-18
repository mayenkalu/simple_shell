#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *get_prompt_string(char *str);
char *get_relative_dir(char *working_dir);

/**
 * prompt - shows shell prompt and waits for user to
 * enter a command
 *
 * Return: void
*/
char *prompt(void)
{
	char *input = NULL;
	char *prompt_string = NULL;
	ssize_t chars_read;
	size_t size = 0;

	prompt_string = "$ ";
	_puts(prompt_string);

	chars_read = getline(&input, &size, stdin);

	if (chars_read == -1)
	{
		free(input);
		exit(0);
	}

	/* Get rid of the new line character*/
	input[chars_read - 1] = ' ';

	return (input);
}

/**
 * get_prompt_string - generates the prompt string
 * @str: any string that you'd like before the directory
 *
 * Return: malloc'd string or NULL on error.
*/
char *get_prompt_string(char *str)
{
	char *prompt_string, *working_dir, *tmp;
	int len = 0;

	if (!str)
		return (NULL);

	working_dir = getcwd(NULL, 0);

	if (_strncmp(working_dir, "/home/", 6) == 0)
	{
		tmp = working_dir;
		working_dir = get_relative_dir(tmp);
		free(tmp);

		if (!working_dir)
			return (NULL);
	}

	/* The extra bytes are for the null byte, "$ " characters and color*/
	len = _strlen(str) + _strlen(working_dir) + 7;

	prompt_string = malloc(sizeof(char) * len);

	if (!prompt_string)
		return (NULL);

	_strcpy(prompt_string, str);
	_strcat(prompt_string, working_dir);
	_strcat(prompt_string, "\033[0m$ ");


	free(working_dir);

	return (prompt_string);
}

/**
 * get_relative_dir - replaces the home dir with ~ e.g /home/aweayo/python
 * ---> ~/python
 * @working_dir: string pointer to full dir path
 *
 * Return: malloc'd string or NULL on error and if working_dir doesn't
 * begin with /home/
*/
char *get_relative_dir(char *working_dir)
{
	char *relative_dir = NULL;

	if (!working_dir)
		return (NULL);

	/* If current working directory is a sub directory of home replace with ~*/
	if (_strncmp(working_dir, "/home/", 6) == 0)
	{
		/*
		* Skip over the username of the home directory e.g /home/aweayo/python
		* --> /python
		*/
		working_dir += 6;
		while (*working_dir != '/' && *working_dir)
			working_dir++;

		if (*working_dir == '\0')
			working_dir = "/";

		relative_dir = malloc(sizeof(char) * (_strlen(working_dir) + 2));

		if (!relative_dir)
			return (NULL);

		_strcpy(relative_dir, "~");
		_strcat(relative_dir, working_dir);
		return (relative_dir);
	}

	return (NULL);
}
