#include "shell.h"

/**
 * builtin_env - checks if it is builtin command
 * @cmd: command inputted
 * Return: 0 (success)
 */

int builtin_env(char *cmd)
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
 * built_han - handles execution of builtins
 * @cmd: command imputted
 * @argv: argument vector
 * @stat: pointer to an integer
 * @idx: index of command
 * Return: void
 */
void built_han(char **cmd, char **argv, int *stat, int idx)
{
	if (_strcmp(cmd[0], "exit") == 0)
		shell_ex(cmd, argv, stat, idx);
	else if (_strcmp(cmd[0], "env") == 0)
		env_set(cmd, stat);
}

/**
 * shell_ex - execute the shell builtins
 * @cmd: command inputted
 * @argv: argument vector
 * @stat: pointer to an integer
 * @idx: index of command
 * Return: void
 */
void shell_ex(char **cmd, char **argv, int *stat, int idx)
{
	int i, valex = (*stat);
	char *index, sms[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (possi_tive(cmd[1]))
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

void setenv_com(char **argv);

/**
 * env_set - set the environment variable
 * @cmd: command inputted
 * @stat: pointer to an integer
 * Return: void
 */
void env_set(char **cmd, int *stat)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	for (i = 0; cmd[0]; i++)
		free(cmd[i]), cmd[i] = NULL;
	free(cmd), cmd = NULL;
	(*stat) = 0;
}
