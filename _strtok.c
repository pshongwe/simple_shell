#include "shell.h"

/**
 * _strtok_setup - sets up split of
 * string into multiple tokens
 * @read: string read
 * Return: pointer to shell command string
 */
char **_strtok_setup(char *read)
{
	char *tok = NULL, del[] = " \n";
	char *tem = NULL;
	char **cmd = NULL;
	int count = 0, i = 0;

	if (read == NULL)
		return (NULL);
	tem = _strdup(read);

	tok = _strtok(tem, del);
	if (tok == NULL)
	{
		free(read), read = NULL;
		free(tem), tem = NULL;
		return (NULL);
	}

	while (tok != NULL)
	{
		count++;
		tok = _strtok(NULL, del);
	}
	free(tem), tem = NULL;

	cmd = malloc(sizeof(char *) * (count + 1));
	tok = _strtok(read, del);
	while (tok != NULL)
	{
		cmd[i] = _strdup(tok);
		tok = _strtok(NULL, del);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

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