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

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(e);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
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

	PRINTER(argv[0]);
	PRINTER(": ");
	e = _itoa(cnt);
	PRINTER(e);
	free(e);
	PRINTER(": ");
	PRINTER(inp);
	PRINTER(": not found\n");
}

/**
 * _errorFile - file errors
 * @argv: args array
 * @c: count of errors
 */
void _errorFile(char **argv, int c)
{
	char *e = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(e);
	PRINTER(": Can't open ");
	PRINTER(argv[1]);
	PRINTER("\n");
	free(e);
}
