#include "shell.h"

/**
 * _strtok - tokenizes a string
 * @str: string
 * @delimiters: delimiter
 * Return: pointer to tokenized string
 */
char *_strtok(char *str, char *delimiters)
{
static char *token;
static char *next_token;

if (str != NULL)
{
token = str;
next_token = str;
}
else
{
if (next_token == NULL || *next_token == '\0')
return (NULL);
token = next_token;
}

while (*token != '\0' && _strchr(delimiters, *token) != NULL)
token++;

if (*token == '\0')
{
next_token = NULL;
return (NULL);
}

next_token = token + 1;
while (*next_token != '\0' && _strchr(delimiters, *next_token) == NULL)
next_token++;

if (*next_token != '\0')
{
*next_token = '\0';
next_token++;
}
else
{
next_token = NULL;
}
return (token);
}

/**
 * _strchr - finds a char in a string
 * @s: string
 * @c: char
 * Return: pointer to char in string
 */
char *_strchr(char *s, char c)
{
int i;

while (1)
{
i = *s++;
if (i == c)
return (s - 1);
if (i == 0)
return (NULL);
}
}