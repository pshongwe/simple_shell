#include "shell.h"

/**
 * common_env - checks if built in command
 * @cmd: command input
 * Return: 0 (success)
 */

int common_env(char *cmd)
{
	char *tin_bno[] = {"exit", "env", NULL};
	int i;

	for (i = 0; tin_bno[i]; i++)
	{
		if (_strcmp(cmd, tin_bno[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * common_handler - handles running of built ins
 * @cmd: command input
 * @argv: args array
 * @stat: exit status of command
 * @idx: index of command in command history
 */
void common_handler(char **cmd, char **argv, int *stat, int idx)
{
	if (_strcmp(cmd[0], "exit") == 0)
		cmd_executor(cmd, argv, stat, idx);
	else if (_strcmp(cmd[0], "env") == 0)
		_setenv(cmd, stat, 1);
}

/**
 * cmd_executor - built in command executor
 * @cmd: command input
 * @argv: args array
 * @stat:  exit status of command
 * @idx: index of command in command history
 * Return: void
 */
void cmd_executor(char **cmd, char **argv, int *stat, int idx)
{
	int i, valex = (*stat);
	char *index, sms[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (checkDigit(cmd[1]))
		{
			valex = _atoi(cmd[1]);
		}
		else
		{
			index = _itoa(idx);
			write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, index, _strlen(index));
			write(STDOUT_FILENO, sms, _strlen(sms));
			write(STDOUT_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDOUT_FILENO, "\n", 1);
			free(index);
			for (i = 0; cmd[0]; i++)
				free(cmd[i]), cmd[i] = NULL;
			free(cmd), cmd = NULL;
			return;
		}
	}
	for (i = 0; cmd[0]; i++)
		free(cmd[i]), cmd[i] = NULL;
	free(cmd), cmd = NULL;
	exit(valex);
}

/**
 * _setenv - Set or modify an environment variable
 * @name: The name of the environment variable
 * @value: The value to set
 * @overwrite: Flag to indicate whether to overwrite if the variable already exists
 * Return: 0 on success, -1 on failure
 */
int _setenv(char *name, char *value, int overwrite)
{
int i, env_var_count;
char *new_env_var;
 char **new_environ;

if (name == NULL || value == NULL)
return (-1);

for (i = 0; environ[i] != NULL; i++)
{
if (strncmp(environ[i], name, strlen(name)) == 0
&& environ[i][strlen(name)] == '=')
{
if (!overwrite)
return (0);

free(environ[i]);
environ[i] = (char *)malloc(strlen(name) + strlen(value) + 2);
if (environ[i] == NULL)
return (-1);


sprintf(environ[i], "%s=%s", name, value);
return (0);
}
}

new_env_var = (char *)malloc(strlen(name) + strlen(value) + 2);
if (new_env_var == NULL)
return (-1);

sprintf(new_env_var, "%s=%s", name, value);

env_var_count = 0;
while (environ[env_var_count] != NULL)
{
env_var_count++;
}
new_environ = (char **)malloc((env_var_count + 2) * sizeof(char *));
if (new_environ == NULL)
{
free(new_env_var);
return (-1);
}
for (i = 0; i < env_var_count; i++)
{
new_environ[i] = environ[i];
}
new_environ[env_var_count] = new_env_var;
new_environ[env_var_count + 1] = NULL;
environ = new_environ;
return (0);
}
