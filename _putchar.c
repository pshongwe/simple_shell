#include "shell.h"

/**
 * _putchar - writes to the standard output
 * @c: charater to be printed
 * Return: what to print
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
