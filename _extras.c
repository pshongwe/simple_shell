#include "shell.h"

/**
 * _parseCmd - parse stdin command
 * @inp: string
 * Return: pointer to parsed string
 */
char **_parseCmd(char *inp)
{
	char **args;
	char *arg;
	int i;

	if (inp[0] == ' ' && inp[_strlen(inp)] == ' ')
		exit(0);
	if (inp == NULL)
		return (NULL);
	args = malloc(sizeof(char *) * BUFSIZE);
	if (args == NULL)
	{
		free(args);
		perror("hsh");
		return (NULL);
	}
	arg = _strtok(inp, DELIMITER);
	while (arg)
	{
		args[i] = arg;
		arg = _strtok(NULL, DELIMITER);
        i++;
	}
	args[i] = NULL;
	return (args);
}

/**
 * _myEcho - calls echo command
 * @cmd: command
 * Return: 0 (S), -1 (F)
 */
int _myEcho(char **cmd, int u)
{
    pid_t pid;
	int status;

	(void)u;
    pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		while (!WIFEXITED(status) && !WIFSIGNALED(status)){
            waitpid(pid, &status, WUNTRACED);
        }
	}
	return (1);
}