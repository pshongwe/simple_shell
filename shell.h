#ifndef SHELL_H
#define SHELL_H

#define BUFF_SIZE 10240
#define PRINTER(s) (write(STDERR_FILENO, s, _strlen(s)))

/* Headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

char **_strtok(char *read);
int get_execute(char **cmd, char **argv, int idx);
char *custom_env(char *name);
char *_getLocation(char *cmd);
char *_getline(void);
extern char **environ;
void _unsetenv(char **argv);
void setenv_init(char **argv);
void cd_com(char **argv);
char *getcwd(char *buf, size_t size);

/* helper prototypes */
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void _print_string(char *str);
int print_number(int n);
int _putchar(char c);
int _strncmp(const char *s1, const char *s2, size_t num);

/* function prototypes */
int isBuiltInCmd(char *cmd);
void common_handler(char **cmd, char **argv, int *stat, int idx);
void cmd_executor(char **cmd, char **argv, int *stat, int idx);
void _setenv(char **cmd, int *stat);
int _echo(char **cmd);
int _echoCases(char **cmd, int status);

/* extra functions */
int checkDigit(char *str);
int _atoi(char *str);
char *_itoa(int n);

#endif /* SHELL_H */
