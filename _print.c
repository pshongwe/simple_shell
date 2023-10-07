#include "shell.h"


/**
 * _print_string - prints string with a new line
 * @str: the string to be printed
 *
 * return: void
 */

void _print_string(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}

/**
 * custom_env - finds my environment
 * @name: the environment
 * Return: charater
 */
char *custom_env(char *name)
{
	size_t len_name = _strlen(name);
	char **envp;

	for (envp = environ; *envp != NULL; ++envp)
	{
		if (_strncmp(*envp, name, len_name) == 0 && (*envp)[len_name]
				== '=')
		{
			return (&((*envp)[len_name + 1]));
		}
	}
	return (NULL);
}

/**
 * _strncmp - comapres two strings
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
