#include "shell.h"

/**
 * _showHistory - show simple shell history
 * Return: 0 success or -1 if fail
 */
int _showHistory(char **ca, int u)
{
	char *fn = ".ss_history"; 
	char *errors, *line = NULL;
    FILE *f;
	size_t len = 0, count = 0;;

	(void)ca;
	(void)u;
	f = fopen(fn, "r");
	if (f == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, f)) != -1)
	{
    count++;
    errors = _itoa(count);
    _printStdErr(errors);
    free(errors);
    _printStdErr(" ");
    _printStdErr(line);
	}
	if (line != NULL)
		free(line);
	fclose(f);
	return (0);
}

/**
 * _history - store input in file
 * @input: input
 * Return: 0 (success), -1 (failure)
 */
int _history(char *inp)
{
	char *fn = ".ss_history";
	ssize_t wr, fd;
	int len = 0;

	if (fn == NULL)
		return (-1);
	fd = open(fn, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (inp)
	{
		while (inp[len])
			len++;
		wr = write(fd, inp, len);
		if (wr < 0)
			return (-1);
	}
	return (1);
}

/**
 * _showEnv - show env vars
 * Return: Always 0
 */
int _showEnv(char **ca, int u)
{
	size_t i = 0;
	int len;

	(void)ca;
	(void)u;
	while (environ[i] != NULL)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
        i++;
	}
	return (0);
}