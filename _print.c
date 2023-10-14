#include "shell.h"

/**
 * _printString - prints string with a new line
 * @str: the string to be printed
 *
 * return: void
 */
void _printString(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}

/**
 * _printStringOnly - prints string only
 * @str: the string to be printed
 * return: void
 */
void _printStringOnly(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
}

/**
 * _strncmp - compares two strings
 * @s1: first string
 * @s2: second string
 * @num: specified number of characters
 * Return: 0 (success)
 */
int _strncmp(const char *s1, const char *s2, size_t num)
{
	size_t i;

	for (i = 0; i < num; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == '\0')
			return (0);
	}
	return (0);
}

/*
 * _printSpecial - prints to stderr
 *
 * @s: input string
 *
 * Return: nothing
 */
void _printSpecial(char *s)
{
write(STDERR_FILENO, s, _strlen(s));
}
