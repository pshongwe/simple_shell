#include "shell.h"

/**
 *  _pError - prints error
 * @argv: args array
 * @c: count of errors
 * @cmd: command string
 */
void _pError(char **argv, int ce, char **cmd)
{
	char *e = _itoa(ce);

	_printStdErr(argv[0]);
	_printStdErr(": ");
	_printStdErr(e);
	_printStdErr(": ");
	_printStdErr(cmd[0]);
	_printStdErr(": Illegal number: ");
	_printStdErr(cmd[1]);
	_printStdErr("\n");
	free(e);
}

/**
 * _printError - shows error
 * @input: input
 * @cnt: counter
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 */

void _printError(char *inp, int cnt, char **argv)
{
	char *e;

	_printStdErr(argv[0]);
	_printStdErr(": ");
	e = _itoa(cnt);
	_printStdErr(e);
	free(e);
	_printStdErr(": ");
	_printStdErr(inp);
	_printStdErr(": not found\n");
}

/**
 * _errorFile - file errors
 * @argv: args array
 * @c: count of errors
 */
void _errorFile(char **argv, int c)
{
	char *e = _itoa(c);

	_printStdErr(argv[0]);
	_printStdErr(": ");
	_printStdErr(e);
	_printStdErr(": Can't open ");
	_printStdErr(argv[1]);
	_printStdErr("\n");
	free(e);
}