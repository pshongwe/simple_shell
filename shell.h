#ifndef SHELL_H
#define SHELL_H

extern char **environ;

/* constants */

#define DELIMITER " \r\a\t\n"
#define BUFSIZE 1024


/* headers */
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/* Structures */

/**
 * struct btin_ - struct for
 * built-in commands with the relevant function
 * @cmd: - built-in command
 * @function: - Pointer to relevant functions
 */
typedef struct btin_
{
	char *cmd_;
	int (*myfunc)(char **, int);
} btin_t;

/* prototypes */

char *_memcpy(char *, char *, unsigned int);
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
void _freeAll(char **, char *);

char *_strncpy(char *, char *, int);
int _atoi(char *);
char *_strcpy(char *, char *);
int _strlen(char *);
void _puts(char *);
int _strcmp(char *, char *);
int _isalpha(int);
void reverseArray(char *, int);
int _putchar(char);
void _printString(char *);
void _printStdErr(char *s);
char *_strcat(char *, char *);
int _strncmp(const char *, const char *, size_t);
char *_strchr(char *, char);
char *_itoa(unsigned int);
char *_strdup(char *);

void _readFile(char *, char **);
void _parseFile(char *, int, FILE *, char **);
void _myExitFile(char **, char *, FILE *);

unsigned int _checkDelim(char, const char *);
char *_getLine(void);
int _hist(char *);
char *_space(char *);
char *_strtok(char *, char *);
void _prompt(void);
void _commentHandler(char *);
char *_enter(char *);
char **_sep(char *);

void _pError(char **, int, char **);
void _printError(char *, int, char **);
void _errorFile(char **, int);

int _findCmd(char **, char *, int c, char **);
int _handleBuiltinCmd(char **, int);
void _signalHandler(int);
char **_parseCmd(char *);

void createEnv(char **);
void freeEnv(char **);

void _printNumberInt(int);
void _printNumber(unsigned int);
int _myEcho(char **, int); 

int _pathCmd(char **);
char *_build_(char *, char *);
char *_getEnv(char *);

void _helpEnv(void);
int _showHelp(char **, int);
void _helpUnsetenv(void);
void _helpSetenv(void);
void _helpHistory(void);
void _helpAlias(void);
void _helpAll(void);
void _helpCd(void);
void _helpHelp(void);
void _helpExit(void);

int _isBuiltinCmd(char **);
void _myExit(char **, char *, char **, int, int);
int _handleBuiltinCmd(char **, int);
int _showEnv(char **, int);
int _changeDir(char **, int);
int _showHistory(char **, int);

#endif /* SHELL_H */
