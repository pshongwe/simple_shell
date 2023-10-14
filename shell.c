#include "shell.h"

/**
 * _signalHandler - allows C^ to terminate shell
 * @sg: signal
 */
void _signalHandler(int sg)
{
	if (sg == SIGINT)
	{
		_printString("\n$ ");
	}
}

/**
 * main - entry point
 * @ac: args count
 * @argv: args array
 * Return: 0
 */
int main(int ac, char **argv)
{
char **cmd, **cmds, *entry;
int i, cnt = 0, status = 0;

(void)ac;
if (argv[1] != NULL)
_readFile(argv[1], argv);
signal(SIGINT, _signalHandler);
while (1)
{
cnt++;
if (isatty(STDIN_FILENO))
_prompt();
entry = _getLine();
if (entry[0] == '\0')
continue;
_hist(entry);
cmds = _sep(entry);
i = 0;
while (cmds[i] != NULL)
{
	cmd = _parseCmd(cmds[i]);
	if (_strcmp(cmd[0], "exit") == 0)
	{
		free(cmds);
		_myExit(cmd, entry, argv, cnt, status);
	}
	else if (_isBuiltinCmd(cmd) == 0)
	{
		status = _handleBuiltinCmd(cmd, status);
		free(cmd);
		continue;
	}
	else
		status = _findCmd(cmd, entry, cnt, argv);
	free(cmd);
	i++;
}
free(entry);
free(cmds);
wait(&status);
}
return (status);
}
