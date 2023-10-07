#include "shell.h"

/**
 * _putchar - writes to standard output
 * @c: character to print
 * Return: ASCII number of the char
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
