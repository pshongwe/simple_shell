#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return:int
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 != '\0' && *s2 != '\0')
{
if (*s1 != *s2)
{
return (*s1 - *s2);
}
s1++;
s2++;
}
return (*s1 - *s2);
}

/**
 * _strdup - duplicates a string and returns pointer
 * to new string
 * @str: string for duplication
 * Return: NULL if str = null or string duplicate
 */
char *_strdup(char *str)
{
	char *result;
	int i = 0, len = 0;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	result = (char *)malloc((sizeof(char) * len) + 1);
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

/**
 * _strcpy - copy src to dest
 * @dest: string to copy to
 * @src: string to copy from
 * Return: string copy
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}

/**
 * _strcat - combines two strings
 * @dest: first string
 * @src: second string
 * Return: string concatenation result
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

/**
 * _strlen - returns string length
 * @s: string to measure
 * Return: length of string
 */
int _strlen(char *s)
{
	size_t a = 0;

	for (; *s++ != '\0';)
		a++;
	return (a);
}
