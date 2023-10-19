#include "shell.h"

ssize_t _getline(char **linep, size_t *linecapp, FILE *stream);

/**
 * _getline - custom getline function
 *
 * Return: line
 */
ssize_t _getline(char **linep, size_t *linecapp, FILE *stream)
{
ssize_t linelen = 0;
int c;
size_t position = 0;

if (linep == NULL || linecapp == NULL || stream == NULL)
return (-1);

if (*linep == NULL || *linecapp == 0)
{
*linecapp = 128;
*linep = (char *)malloc(*linecapp);
if (*linep == NULL)
return (-1);
}

while (1)
{
c = fgetc(stream);

if (c == EOF || c == '\n')
{
(*linep)[position] = '\0';
break;
}

(*linep)[position] = (char)c;
position++;

if (position >= *linecapp - 1)
{
*linecapp *= 2;
char *temp = (char *)realloc(*linep, *linecapp);
if (temp == NULL)
return (-1);
*linep = temp;
}
linelen++;
}
if (linelen == 0 && c == EOF)
return (-1);
return (linelen);
}