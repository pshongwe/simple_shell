#include "shell.h"

/**
 *  _pError - prints error
 * @argv: args array
 * @ce: count of errors
 * @cmd: command string
 */
void _pError(char **argv, int ce, char **cmd)
{
	char *e = _itoa(ce);

	_printSpecial(argv[0]);
	_printSpecial(": ");
	_printSpecial(e);
	_printSpecial(": ");
	_printSpecial(cmd[0]);
	_printSpecial(": Illegal number: ");
	_printSpecial(cmd[1]);
	_printSpecial("\n");
	free(e);
}

/**
 * _printError - shows error
 * @inp: input
 * @cnt: counter
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 */

void _printError(char *inp, int cnt, char **argv)
{
	char *e;

	_printSpecial(argv[0]);
	_printSpecial(": ");
	e = _itoa(cnt);
	_printSpecial(e);
	free(e);
	_printSpecial(": ");
	_printSpecial(inp);
	_printSpecial(": not found\n");
}

/**
 * _errorFile - file errors
 * @argv: args array
 * @c: count of errors
 */
void _errorFile(char **argv, int c)
{
	char *e = _itoa(c);

	_printSpecial(argv[0]);
	_printSpecial(": ");
	_printSpecial(e);
	_printSpecial(": Can't open ");
	_printSpecial(argv[1]);
	_printSpecial("\n");
	free(e);
}
