#include "shell.h"

/**
 * main - entry point
 * @ac: The first argument in main
 * @argv: The second argument in main
 *
 * Return: 0
 */

int main(int ac, char **argv)
{
char *read = NULL;
char **cmd = NULL;
size_t size = 0;
ssize_t n_char;
int stat = 0, idx = 0;

(void)ac;

while (1)
{
	if (isatty(0))
		write(STDOUT_FILENO, "(darkshell)$ ", 13);
	n_char = getline(&read, &size, stdin);
	if (n_char == -1)
	{
		if (isatty(0))
			_puts("\n");
		free(read), read = NULL;
		return (stat);
	}
	idx++;

	cmd = str_token(read);
	if (cmd == NULL)
		continue;

	if (common_env(cmd[0]))
		common_handler(cmd, argv, &stat, idx);
	else
		stat = get_execute(cmd, argv, idx);
}
}
