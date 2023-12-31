#include "shell.h"

/**
 * isBuiltInCmd - checks if built in command
 * @cmd: command input
 * Return: 0, 1
 */

int isBuiltInCmd(char *cmd)
{
	char *buildInCmds[] = {"exit", "env", "echo", NULL};
	int i;

	for (i = 0; buildInCmds[i]; i++)
	{
		if (_strcmp(cmd, buildInCmds[i]) == 0)
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
		_setenv(cmd, stat);
	else if (_strcmp(cmd[0], "echo") == 0)
		_echoCases(cmd, *stat);
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
			for (i = 0; cmd[i]; i++)
				free(cmd[i]), cmd[i] = NULL;
			free(cmd), cmd = NULL;
			return;
		}
	}
	for (i = 0; cmd[i]; i++)
		free(cmd[i]), cmd[i] = NULL;
	free(cmd), cmd = NULL;
	exit(valex);
}

/**
 * _setenv - set the environment variables
 * @cmd: command input
 * @stat: exit status of command
 */
void _setenv(char **cmd, int *stat)
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

/**
 * _echoCases - echo cases
 * @cmd: command
 * @status: status, last command called
 * Return: Always 1 (Success)
 */
int _echoCases(char **cmd, int status)
{
char *path;
unsigned int pid = getppid();

if (_strncmp(cmd[1], "$?", 2) == 0)
{
print_number(status);
PRINTER("\n");
}
else if (_strncmp(cmd[1], "$PATH", 5) == 0)
{
path = custom_env("PATH");
PRINTER(path);
PRINTER("\n");
free(path);
}
else if (_strncmp(cmd[1], "$$", 2) == 0)
{
print_number(pid);
PRINTER("\n");
}
else
return (_echo(cmd));
return (1);
}
