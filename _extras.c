#include "shell.h"

/**
 * _parseCmd - parse stdin command
 * @inp: string
 * Return: pointer to parsed string
 */
char **_parseCmd(char *inp)
{
char **args;
char *arg;
int i;

if (inp[0] == ' ' && inp[_strlen(inp)] == ' ')
exit(0);
if (inp == NULL)
return (NULL);
args = malloc(sizeof(char *) * BUFSIZE);
if (args == NULL)
{
freeSafe(args);
perror("hsh");
return (NULL);
}
arg = _strtok(inp, DELIMITER);
while (arg)
{
args[i] = arg;
arg = _strtok(NULL, DELIMITER);
i++;
}
args[i] = NULL;
return (args);
}

/**
 * _myEcho - calls echo command
 * @cmd: command
 * @u: status
 * Return: 0 (S), -1 (F)
 */
int _myEcho(char **cmd, int u)
{
pid_t pid;
int status;

(void)u;
pid = fork();
if (pid == 0)
{
if (execve("/bin/echo", cmd, environ) == -1)
return (-1);
exit(EXIT_FAILURE);
}
else if (pid < 0)
return (-1);
else
{
while (!WIFEXITED(status) && !WIFSIGNALED(status))
waitpid(pid, &status, WUNTRACED);
}
return (1);
}

/**
 * _build_ - build command
 * @tk: token/cmd
 * @val: Directory conatining Command
 * Return: Parsed full path of command or NULL if failed
 */
char *_build_(char *tk, char *val)
{
size_t len;
char *cmd;

len = _strlen(val) + _strlen(tk) + 2;
cmd = malloc(sizeof(char) * len);
if (cmd == NULL)
{
freeSafe(cmd);
return (NULL);
}
_memset(cmd, 0, len);
cmd = _strcat(cmd, val);
cmd = _strcat(cmd, "/");
cmd = _strcat(cmd, tk);
return (cmd);
}

/**
 * _enter - handle /n
 * @string: string
 * Return: empty string
 */
char *_enter(char *string)
{
freeSafe(string);
return ("\0");
}

void freeSafe(void *ptr)
{
    if (ptr != NULL) 
        free(ptr);
    ptr = NULL;
}