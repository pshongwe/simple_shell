#include "shell.h"

/**
 * main - entry point
 * @ac: number of args
 * @argv: args array
 *
 * Return: 0
 */
int main(int ac, char **argv)
{
char *read = NULL, *mystatus = NULL;
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
			_print_string("\n");
		free(read), read = NULL;
		return (stat);
	}
	idx++;

	cmd = _strtok_setup(read);
	if (cmd == NULL)
		continue;
mystatus = _itoa(stat);
if (common_env(cmd[0]))
common_handler(cmd, argv, mystatus, idx);
else
stat = get_execute(cmd, argv, idx);
}
}
