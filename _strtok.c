#include "shell.h"
/**
 * _strtok - splits string into multiple tokens
 * @read: string read
 * Return: pointer to shell command string
 */
char **_strtok(char *read)
{
	char *tok = NULL, del[] = " \n\a\t\r";
	char *tem = NULL;
	char **cmd = NULL;
	int count = 0, i = 0;

	if (read == NULL)
		return (NULL);
	tem = _strdup(read);
	tok = strtok(tem, del);
	if (tok == NULL)
	{
		free(tem), tem = NULL;
		free(read), read = NULL;
		return (NULL);
	}

	while (tok != NULL)
	{
		count++;
		tok = strtok(NULL, del);
	}
	free(tem), tem = NULL;
	cmd = malloc(sizeof(char *) * (count + 1));
	tok = strtok(read, del);
	while (tok != NULL)
	{
		cmd[i] = _strdup(tok);
		tok = strtok(NULL, del);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
