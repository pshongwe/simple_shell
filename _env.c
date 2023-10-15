#include "shell.h"

/**
 * _freeSafeEnv - freeSafes the memory of env vars
 * @e:  arrays of env vars
 */
void _freeSafeEnv(char **e)
{
int i;

for (i = 0; e[i]; i++)
{
freeSafe(e[i]);
}
}

/**
 * _getEnv - Retrieve value of an environment var
 * @varName: name of the environment variable to retrieve
 * Return: If the variable is found, a pointer to its value
 * is returned; otherwise, NULL is returned.
 */
char *_getEnv(const char *varName)
{
int i;
char *value, *entry;

for (i = 0; environ[i] != NULL; i++)
{
entry = environ[i];
if (_strncmp(entry, varName, _strlen(varName)) == 0)
{
value = _strchr(entry, '=');
if (value != NULL)
{
return (value + 1);
}
}
}
return (NULL);
}

/**
 * _createEnv - creates array of vars
 * @e: array for storing env vars
 */

void _createEnv(char **e)
{
int i;

for (i = 0; environ[i]; i++)
e[i] = _strdup(environ[i]);
e[i] = NULL;
}

/**
 * _pathCmd - search $PATH for command
 * @cmd: command
 * Return: 0 (success), 1 (failure)
 */
int _pathCmd(char **cmd)
{
struct stat buff_;
char *value, *path, *cmdPath;

path = _getEnv("PATH");
value = _strtok(path, ":");
while (value != NULL)
{
cmdPath = _build_(*cmd, value);
if (stat(cmdPath, &buff_) == 0)
{
*cmd = _strdup(cmdPath);
freeSafe(path);
freeSafe(cmdPath);
return (0);
}
freeSafe(cmdPath);
value = _strtok(NULL, ":");
}
freeSafe(value);
freeSafe(path);
return (1);
}
