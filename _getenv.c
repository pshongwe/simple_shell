#include "shell.h"

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

			if (stat(fullpath, &buff) == 0)
			{
				return (fullpath);
			}
			else
			{
				_freeSafe(fullpath);
				pathdir = strtok(NULL, ":");
			}
		}
	return (NULL);
}
