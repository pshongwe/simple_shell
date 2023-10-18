#include "shell.h"

/**
 * _septor - delimits string entry with ;
 * @entry: input entry
 * Return: pointer to command strings
 */
char **_septor(char *entry)
{
	int i, buffsize = BUFF_SIZE;
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
	cmd = strtok(entry, ";&");

	while (cmd)
	{
		cmds[i] = cmd;
		cmd = strtok(NULL, ";&");
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}
