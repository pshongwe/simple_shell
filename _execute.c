#include "shell.h"

/**
 * _findCmd - executes commands as per path
 * @cmd: pointer to command strings
 * @inp: input
 * @c: time count
 * @argv: args array
 * Return: 1 cmd is null,
 * -1 for non-existent command
 * and 0 for success
 */
int _findCmd(char **cmd, char *inp, int c, char **argv)
{
    pid_t pid;
	int waitStatus;

	if (*cmd == NULL)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			_pathCmd(cmd);
		if (access(cmd[0], R_OK) != 0)
		{
			_pError(&cmd[0], c, argv);
			_freeAll(cmd, inp);
			exit(127);
		}
		if (execve(*cmd, cmd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&waitStatus);
if (WIFEXITED(waitStatus))
{
if (WEXITSTATUS(waitStatus) == 0)
return (0);
else if (WEXITSTATUS(waitStatus) == 127)
return (127);
else if (WEXITSTATUS(waitStatus) == 2)
return (2);
}
return (127);
}