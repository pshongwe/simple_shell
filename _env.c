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
char *_getEnv(char *varName)
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

/**
 * _setenv - set env var
 * @name: name
 * @value: value
 * @overwrite: mode
 * Return: int
 */
int _setenv(char *name, char *value, int overwrite)
{size_t env_count = 0, name_length = _strlen(name);
size_t i, value_length = _strlen(value);
char **new_environ, *new_entry = NULL;

new_entry = (char *)malloc(name_length + value_length + 2);
if (!new_entry)
return (-1);
_strcpy(new_entry, name);
new_entry[name_length] = '=';
_strcpy(new_entry + name_length + 1, value);
new_entry[name_length + value_length + 1] = '\0';
while (environ[env_count] != NULL)
env_count++;
for (i = 0; i < env_count; i++)
{
if (_strncmp(environ[i], name, name_length) == 0
&& environ[i][name_length] == '=')
{
if (!overwrite)
{
freeSafe(new_entry);
return (0);
}
freeSafe(environ[i]);
environ[i] = new_entry;
return (0);
}
}
new_environ = (char **)malloc((env_count + 2) * sizeof(char *));
if (!new_environ)
{
freeSafe(new_entry);
return (-1);
}
for (i = 0; i < env_count; i++)
new_environ[i] = environ[i];
new_environ[env_count] = new_entry;
new_environ[env_count + 1] = NULL;
freeSafe(environ);
environ = new_environ;
return (0);
}