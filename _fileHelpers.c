#include "shell.h"

/**
 * _readFile - reads commands from file
 * @fn: file
 * @argv: args array
 * Return: nothing
 */
void _readFile(char *fn, char **argv)
{
FILE *f;
char *l = NULL;
size_t len = 0;
int cnt = 0;

f = fopen(fn, "r");
if (f == NULL)
{
_errorFile(argv, cnt);
exit(127);
}
while ((getline(&l, &len, f)) != -1)
{
cnt++;
_parseFile(l, cnt, f, argv);
}
if (l != NULL)
freeSafe(l);
fclose(f);
exit(0);
}

/**
 * _myExitFile - file input exit handler
 * @l: file line
 * @cmd: command
 * @fd: file descriptor
 */
void _myExitFile(char **cmd, char *l, FILE *fd)
{
int status;
int i = 0;

if (cmd[i] == NULL)
{
freeSafe(cmd);
freeSafe(l);
fclose(fd);
exit(errno);
}
while (cmd[1][i])
{
if (_isalpha(cmd[1][i++]) < 0)
perror("Illegal number");
}
status = _atoi(cmd[1]);
freeSafe(cmd);
freeSafe(l);
fclose(fd);
exit(status);
}


/**
 * _parseFile - parse commands from file
 * @l: file line
 * @cnt: error count
 * @f: file pointer
 * @argv: args array
 */
void _parseFile(char *l, int cnt, FILE *f, char **argv)
{
char **cmd;
int status = 0;

cmd = _parseCmd(l);
if (_strncmp(cmd[0], "exit", 4) == 0)
_myExitFile(cmd, l, f);
else if (_isBuiltinCmd(cmd) == 0)
{
status = _handleBuiltinCmd(cmd, status);
freeSafe(cmd);
}
else
{
status = _findCmd(cmd, l, cnt, argv);
freeSafe(cmd);
}
}
