#ifndef _MAIN_H_
#define _MAIN_H_
int _strlen(char *s);
void _puts(char *s);
void _putchar(char c);
char *_strcpy(char *dest, char *src);
char *prompt(void);
char *_strncpy(char *dest, char *src, int n);
char **split(char *string);
int _strcmp(char *s1, char *s2);
void free_split(char **string);
char *get_command(char *command);
char *_strcat(char *dest, char *src);
char *prefix(char *prefix, char *str);
char *_strdup(char *str);
int _pow(int x, int y);
int _atoi(char *str);
int _strncmp(char *s1, char *s2, unsigned int n);
char *_itoa(int a);
void replace_variables(char **args, int status);
void reverse_string(char *s);
int _abs(int d);
int handle_builtins(char **args, char *program_name);
void print_array(char **array);
char *_getenv(char *var);
void env_handler(char **args);
void exit_handler(char **args);
void cd_handler(char **args);
void (*get_builtin_func(char *command))(char **);
/**
 * struct builtin - struct for built in commands
 * @command: string representing the function command
 * @handler: the function that carries out the command
*/
typedef struct builtin
{
	char *command;
	void (*handler)(char **args);
} builtin_t;
#endif
