#include "shell.h"

/**
 * setenv_init - initializes a new environment variable
 * @argv: args
 * Return: void
 */
void setenv_init(char **argv)
{
	int result;

	if (argv[1] == NULL || argv[2] == NULL)
	{
		_print_string("Usage: setenv VARIABLE VALUE");
	}
	else
	{
	/* TODO: use custom setenv - call it _setenv */
		result = setenv(argv[1], argv[2], 1);
		if (result != 0)
		{
			_print_string("_setenv: Error setting environment variable");
		}
	}
}

/**
 * _unsetenv - remove an environment variable
 * @argv: argument vector
 * Retrurn: void
 */
void _unsetenv(char **argv)
{
	int result;

	if (argv[1] == NULL)
	{
		_print_string("Usage: unsetenv VARIABLE");
	}
	else
	{
		result = unsetenv(argv[1]);
		if (result != 0)
		{
			_print_string("unsetenv: Error unsetting environment var");
		}
	}
}
