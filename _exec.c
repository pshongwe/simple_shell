#include "shell.h"

int get_execute(char **cmd, char **argv, int idx);

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
if (fullcmd != NULL)
{
pid = fork();
if (pid == 0)
{
if (execve(fullcmd, cmd, NULL) == -1)
{
_freeSafe(&fullcmd);
for (i = 0; cmd[i]; i++)
{
	_freeSafe(&cmd[i]);
}
}
}
else
{
waitpid(pid, &stat, 0);
for (i = 0; cmd[i]; i++)
{
_freeSafe(&cmd[i]);
}
_freeSafe(&cmd);
}
_freeSafe(&fullcmd);
return (WEXITSTATUS(stat));
}
else
{
PRINTER(argv[0]);
PRINTER(": ");
PRINTER(cmd[0]);
PRINTER(": ");
PRINTER(_itoa(idx));
PRINTER(": not found\n");
for (i = 0; cmd[i]; i++)
{
_freeSafe(&cmd[i]);
}
_freeSafe(&cmd);
return (127);
}
}
