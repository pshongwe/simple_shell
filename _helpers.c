#include "shell.h"

/**
 * checkDigit - checks if string contains digits
 * @str: the string to check
 * Return: 1 on success or 0 on failure
 */
int checkDigit(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - converts string into integer
 * @str: string to convert to integer
 * Return: integer conversion output
 */
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}

/**
 * _itoa - converts integer to string
 * @n: integer to convert
 * Return: character mapped to integer
 */
char *_itoa(int n)
{
	char buff[10];
	int i = 0;

	if (n == 0)
		buff[i++] = '0';
	else
	{
		while (n > 0)
		{
			buff[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buff[i] = '\0';
	return (_strdup(buff));
}
