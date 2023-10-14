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

/**
 * _space - removes spaces
 * @str: string to remove spaces
 * Return: return clean string
 */
char *_space(char *str)
{
int x = 0, y = 0;
char *b;

b = malloc(sizeof(char) * (_strlen(str) + 1));
if (b == NULL)
{
free(b);
return (NULL);
}
while (str[x] == ' ')
x++;
while (str[x + 1] != '\0')
{
b[y] = str[x];
x++;
y++;
}
b[y] = '\0';
if (b[0] == '\0' || b[0] == '#')
{
free(b);
return ("\0");
}
return (b);
}
