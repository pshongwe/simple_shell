#include "shell.h"

/**
 * _freeEnv - frees the memory of env vars
 * @e:  arrays of env vars
 */
void _freeEnv(char **e)
{
int i;

for (i = 0; e[i]; i++)
{
free(e[i]);
}
}

/**
 * _getEnv - Retrieve value of an environment var
 * @varName: name of the environment variable to retrieve
 * Return: If the variable is found, a pointer to its value
 * is returned; otherwise, NULL is returned.
 */
char *_getEnv(char *varName)
{
char *val;
size_t l, vl;
int x = 0, y = 0, z = 0;

l = _strlen(varName);
while (environ[x])
{
if (_strncmp(varName, environ[x], l) == 0)
{
vl = _strlen(environ[x]) - l;
val = malloc(sizeof(char) * vl);
if (val == NULL)
{
free(val);
perror("unable to allocate memory");
return (NULL);
}
y = 0;
z = l + 1;
while (environ[x][z])
{
val[y] = environ[x][z];
z++;
y++;
}
val[y] = '\0';
return (val);
}
x++;
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
free(path);
free(cmdPath);
return (0);
}
free(cmdPath);
value = _strtok(NULL, ":");
}
free(value);
free(path);
return (1);
}
