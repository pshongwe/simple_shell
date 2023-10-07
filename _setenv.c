#include "shell.h"

/**
 * setenv_com - initializes a new environment variable
 * @argv: argument vector
 * Return: void
 */
void setenv_com(char **argv)
{
	int result;

	if (argv[1] == NULL || argv[2] == NULL)
	{
		_puts("Usage: setenv VARIABLE VALUE");
	}
	else
	{
		result = setenv(argv[1], argv[2], 1);
		if (result != 0)
		{
			_puts("setenv: Error setting environment variable");
		}
	}
}

/**
 * unsetenv_com -remove an environment variable
 * @argv: argument vector
 * Retrurn: void
 */
void unsetenv_com(char **argv)
{
	int result;

	if (argv[1] == NULL)
	{
		_puts("Usage: unsetenv VARIABLE");
	}
	else
	{
		result = unsetenv(argv[1]);
		if (result != 0)
		{
			_puts("unsetenv: Error unsetting environment var");
		}
	}
}
