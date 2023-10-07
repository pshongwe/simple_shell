#include "shell.h"
/**
 * str_token - the function for tokenazetion the string
 * @read: The line of the user enter to be tokenazetion
 *
 * Return: cmd
 */
char **str_token(char *read)
{
	char *tok = NULL, del[] = " \n";
	char *tem = NULL;
	char **cmd = NULL;
	int count = 0, i = 0;

	if (read == NULL)
		return (NULL);
	tem = _strdup(read);

	tok = strtok(tem, del);
	if (tok == NULL)
	{
		free(read), read = NULL;
		free(tem), tem = NULL;
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
