#include "shell.h"

/**
 * _isBuiltinCmd - confirms if command
 * is built-in
 * @cmd: command to verify
 * Return: 0 Success, -1 Fail
 */
int _isBuiltinCmd(char **cmd)
{
	btin_t func[] = {
		{"help", NULL},
        {"cd", NULL},
		{"env", NULL},
        {"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int z;

	if (*cmd == NULL)
		return (-1);
	for (z = 0; (z + func)->cmd_; z++)
	{
		if (_strcmp(cmd[0], (z + func)->cmd_) == 0)
			return (0);
	}
	return (-1);
}

/**
 * _myExit - builtIn command exit
 * @cmd: command string
 * @inp: input
 * @argv: array of args
 * @cnt: time count
 * @status: exit status
 */
void _myExit(char **cmd, char *inp, char **argv, int cnt, int status)
{
	int status_, i = 0;

	if (cmd[1] == NULL)
	{
		free(cmd);
		free(inp);
		exit(status);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_pError(argv, cnt, cmd);
			free(cmd);
			free(inp);
			exit(2);
		}
		else
		{
			status_ = _atoi(cmd[1]);
			if (status_ == 2)
			{
				_pError(argv, cnt, cmd);
				free(cmd);
				free(inp);
				exit(status_);
			}
			free(cmd);
			free(inp);
			exit(status_);
		}
	}
}

/**
 * _handleBuiltinCmd - Handles predefined built
 * in commands
 * @cmd: Array of parsed command strings
 * @st: Status of last execution
 * Return: -1 Failure 0 Success
 */
int _handleBuiltinCmd(char **cmd, int status)
{
	btin_t builtIn[] = {
		{"cd", _changeDir},
		{"env", _showEnv},
		{"help", _showHelp},
		{"echo", _myEcho},
		{"history", _showHistory},
		{NULL, NULL}
	};
	int z;

	for (z = 0; (z + builtIn)->cmd_; z++) 
	{
		if (_strcmp(cmd[0], (z + builtIn)->cmd_) == 0)
		{
			return ((z + builtIn)->myfunc(cmd, status));
		}
	}
	return (-1);
}