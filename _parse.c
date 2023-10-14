#include "shell.h"


/**
 * _prompt - prints prompt
 */
void _prompt(void)
{
	_printString("$ ");
}

/**
 * _sep - delimits string entry with ;
 * @input: input entry
 * Return: pointer to command strings
 */
char **_sep(char *entry)
{
	int i = 0, buffsize = BUFSIZE;
    char **cmds, *cmd;

	if (entry[_strlen(entry)] == ' ' && entry[0] == ' ')
		exit(0);
	if (entry == NULL)
		return (NULL);
	cmds = malloc(sizeof(char *) * buffsize);
	if (cmds == NULL)
	{
		free(cmds);
		perror("hsh");
		return (NULL);
	}
	cmd = _strtok(entry, ";&");
	while (cmd)
	{
		cmds[i] = cmd;
		cmd = _strtok(NULL, ";&");
        i++;
	}
	cmds[i] = NULL;
	return (cmds);
}