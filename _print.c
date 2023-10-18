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

/**
 * _echo - executes echo function
 * @cmd: command
 * Return: 0 (Success), -1 (Failure)
 */
int _echo(char **cmd)
{
int sts, firstTime;
pid_t pid;

pid = fork();
if (pid == 0)
{
if (execve("/bin/echo", cmd, environ) == -1)
return (-1);
exit(EXIT_FAILURE);
}
else if (pid < 0)
return (-1);
else
{
for (firstTime = 1; firstTime || (!WIFEXITED(sts)
&& !WIFSIGNALED(sts)); firstTime = 0)
{
waitpid(pid, &sts, WUNTRACED);
}
}
return (1);
}

/**
* print_number - Prints an integer using putchar
* @n: number
* Return: Updated count of characters printed.
*/
int print_number(int n)
{
unsigned int divisor;
unsigned int num;
int count;

count = 0;
num = (unsigned int)n;
if ((signed int)num < 0)
{
num = -num;
_putchar('-');
count++;
}
divisor = 1;
while (num / divisor > 9)
divisor *= 10;
while ((signed int)divisor > 0)
{
_putchar('0' + num / divisor);
num %= divisor;
divisor /= 10;
count++;
}
return (count);
}
