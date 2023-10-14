#include "shell.h"

/**
 * _atoi - converts string to int
 * @str: string for conversion
 * Return: int result
 */
int _atoi(char *str)
{
int result = 0, i = 0;

while (str[i])
{
result *= 10;
result += (str[i] - '0');
i++;
}
return (result);
}

/**
 * _itoa - converts int to string
 * @number: unsigned int
 * Return: string
 */
char *_itoa(unsigned int number)
{
int i = 0;
char b[10];

if (number == 0)
b[i++] = '0';
else
{
while (number > 0)
{
b[i++] = (number % 10) + '0';
number /= 10;
}
}
b[i] = '\0';
return (_strdup(b));
}
