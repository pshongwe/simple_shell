#include "shell.h"

/**
 * getmy_loc - retreive my path
 * @mycommand: command to be inputed
 * Return: my path
 */
char *getmy_loc(char *mycommand)
{
	char *path, *fullpath, *pathdir;
	int i;
	struct stat buff;

	for (i = 0; mycommand[i]; i++)
	{
		if (mycommand[i] == '/')
		{
			if (stat(mycommand, &buff) == 0)
				return (_strdup(mycommand));
			else
				return (NULL);
		}
	}
	    path = custom_env("PATH");


		pathdir = strtok(path, ":");
		while (pathdir != NULL)
		{
			fullpath = malloc(_strlen(pathdir) + _strlen(mycommand) + 2);
			_strcpy(fullpath, pathdir);
			_strcat(fullpath, "/");
			_strcat(fullpath, mycommand);

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
	return (NULL);
}
