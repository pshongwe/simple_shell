#include "shell.h"

/**
 * _commentHandler - removes text after #
 * @b: buffer
 * Return: nothing
 */
void _commentHandler(char *b)
{
	int i = 0;

	while (b[i] != '\0')
	{
		if (b[i] == '#' && b[i + 1] == ' ' && b[i - 1] == ' ')
		{
			b[i] = '\0';
		}
        i++;
	}
}

/**
 * _getLine - read from std input
 * Return: input in buffer
 */
char *_getLine()
{
	int _read, i;
	char c = 0;
    char *buf, *buffer;

	buffer = malloc(1024);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	for (i = 0; c != '\n' && c != EOF; i++)
	{
		fflush(stdin);
		_read = read(STDIN_FILENO, &c, 1);
		if (_read == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[i] = c;
		if (buffer[0] == '\n')
			return (_enter(buffer));
		if (i >= 1024)
		{
			buffer = _realloc(buffer, (1024 + 2), 10 * (1024 + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[i] = '\0';
	buf = _space(buffer);
	free(buffer);
	_commentHandler(buf);
	return (buf);
}