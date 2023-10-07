#include "shell.h"

/**
 * _getline - custom getline function
 *
 * Return: line
 */
char *_getline(void)
{
	static char buff[BUFF_SIZE];
	static size_t buff_idx;
	static ssize_t bread;
	char *myline = NULL;
	char cur_char;
	size_t llen = 0;

	buff_idx = 0;
	bread = 0;

	while (1)
	{
		if (buff_idx >= (size_t)bread)
		{
			bread = read(STDIN_FILENO, buff, BUFF_SIZE);
			buff_idx = 0;

			if (bread <= 0)
			{
				if (llen > 0)
				{
					break;
				}
				else
				{
					return (NULL);
				}
			}
		}
		cur_char = buff[buff_idx++];
		if (cur_char == '\n' || cur_char == '\r')
		{
			break;
		}
		if (llen % BUFF_SIZE == 0)
		{
			myline = realloc(myline, (llen + BUFF_SIZE) * sizeof(char));
			if (myline == NULL)
			{
				perror("Memory alloation error");
				exit(1);
			}
		}
		myline[llen++] = cur_char;
	}
	if (myline == NULL && llen == 0)
	{
		return (NULL);
	}
	myline = realloc(myline, (llen + 1) * sizeof(char));
	if (myline == NULL)
	{
		perror("Memory allocation error");
		exit(1);
	}
	myline[llen] = '\0';

	return (myline);
}
