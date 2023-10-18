#include "shell.h"

int get_execute(char **cmd, char **argv, int idx);

/**
 * get_execute - The function for execute the file
 * @cmd: the command who the user enter
 * @argv: The name of the shell and others
 * @idx: index
 *
 * Return: WEXITSTATUS(var_st)
 */
int get_execute(char **cmd, char **argv, int idx)
{
	char *fullcmd;
	pid_t pid;
	int stat, i;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		exit(0);
	}

	fullcmd = _getLocation(cmd[0]);

	if (fullcmd != NULL)
	{
		pid = fork();

		if (pid == 0)
		{
			if (execve(fullcmd, cmd, NULL) == -1)
			{
				free(fullcmd), fullcmd = NULL;

				for (i = 0; cmd[i]; i++)
				{
					free(cmd[i]), cmd[i] = NULL;
				}
				free(cmd), cmd = NULL;
			}
		}
		else
		{
			waitpid(pid, &stat, 0);
			for (i = 0; cmd[i]; i++)
			{
				free(cmd[i]), cmd[i] = NULL;
			}
			free(cmd), cmd = NULL;
			free(fullcmd), fullcmd = NULL;
		}
		return (WEXITSTATUS(stat));
	}
	else
	{
		printf("%s: %s: %d: not found\n", argv[0], cmd[0], idx);
		for (i = 0; cmd[i]; i++)
		{
			free(cmd[i]), cmd[i] = NULL;
		}
		free(cmd), cmd = NULL;
		return (127);
	}
}
