#include "shell.h"

/**
 * get_execute - execute function
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
		exit(0);
	fullcmd = _getLocation(cmd[0]);
	if (!fullcmd)
	{
		PRINTER(argv[0]);
		PRINTER(": ");
		PRINTER(cmd[0]);
		PRINTER(": ");
		PRINTER(_itoa(idx));
		PRINTER(": not found\n");
		for (i = 0; cmd[0]; i++)
			freeSafe(cmd[i]), cmd[i] = NULL;
		freeSafe(cmd), cmd = NULL;
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			freeSafe(fullcmd), fullcmd = NULL;
			for (i = 0; cmd[i]; i++)
				freeSafe(cmd[i]), cmd[i] = NULL;
			freeSafe(cmd), cmd = NULL;
		}
	}
	else
	{
		waitpid(pid, &stat, 0);
		for (i = 0; cmd[i]; i++)
			freeSafe(cmd[i]), cmd[i] = NULL;
		freeSafe(cmd), cmd = NULL;
		freeSafe(fullcmd), fullcmd = NULL;
	}
	return (WEXITSTATUS(stat));
}
