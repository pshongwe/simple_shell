#ifndef SHELL_H
#define SHELL_H

#define BUFF_SIZE 1024

extern char **environ;

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

char **_strtok_setup(char *read);
char *_strtok(char *str, char *delimiters);
int get_execute(char **cmd, char **argv, int idx);
char *custom_env(char *name);
char *_getLocation(char *cmd);
char *_getline(void);
void *_realloc(void *ptr, size_t new_size);

void _unsetenv(char **argv);
void setenv_init(char **argv);
int _setenv(char *name, char *value, int overwrite);
void cd_com(char **argv);
char *getcwd(char *buf, size_t size);

/* helper prototypes */
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
void _print_string(char *str);
int _putchar(char c);
int _strncmp(const char *s1, const char *s2, size_t num);
size_t malloc_usable_size(void *ptr);

/* function prototypes */
int common_env(char *cmd);
void common_handler(char **cmd, char **argv, int *stat, int idx);
void cmd_executor(char **cmd, char **argv, int *stat, int idx);

/* extra functions */
int checkDigit(char *str);
int _atoi(char *str);
char *_itoa(int n);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif /* SHELL_H */
