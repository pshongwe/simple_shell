#include "shell.h"
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

	fullcmd = getmy_loc(cmd[0]);
	if (!fullcmd)
	{
		printf("%s: ", argv[0]);
		printf("%s: ", cmd[0]);
		printf("%d: not found\n", idx);
		for (i = 0; cmd[0]; i++)
			free(cmd[i]), cmd[i] = NULL;
		free(cmd), cmd = NULL;
		return (127);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			free(fullcmd), fullcmd = NULL;
			for (i = 0; cmd[i]; i++)
				free(cmd[i]), cmd[i] = NULL;
			free(cmd), cmd = NULL;
		}
	}
	else
	{
		waitpid(pid, &stat, 0);
		for (i = 0; cmd[i]; i++)
			free(cmd[i]), cmd[i] = NULL;
		free(cmd), cmd = NULL;
		free(fullcmd), fullcmd = NULL;
	}
	return (WEXITSTATUS(stat));
}
