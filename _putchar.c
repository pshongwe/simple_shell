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

/**
 * _isalpha - check if char is alphabet
 * @c: a char
 * Return: int
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
