#include "shell.h"

char *_getLocation(char *cmd);

/**
 * _getLocation - retrieve cmd from path
 * @cmd: command to be input
 * Return: location
 */
char *_getLocation(char *cmd)
{
char *path, *fullpath, *pathdir;
int i;
struct stat buff;

for (i = 0; cmd[i]; i++)
{
	if (cmd[i] == '/')
	{
		if (stat(cmd, &buff) == 0)
			return (_strdup(cmd));
		else
			return (NULL);
	}
}
path = custom_env("PATH");
pathdir = strtok(path, ":");
while (pathdir != NULL)
{
fullpath = malloc(_strlen(pathdir) + _strlen(cmd) + 2);
_strcpy(fullpath, pathdir);
_strcat(fullpath, "/");
_strcat(fullpath, cmd);
_strcat(fullpath, "\0");
if (stat(fullpath, &buff) == 0)
{
return (fullpath);
}
else
{
free(fullpath);
pathdir = strtok(NULL, ":");
}
}
if (stat(cmd, &buff) == 0)
{
return (cmd);
}
return (NULL);
}
