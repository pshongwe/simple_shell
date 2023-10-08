#include "shell.h"
#include <malloc.h>

/**
 * checkDigit - checks if string contains digits
 * @str: the string to check
 * Return: 1 on success or 0 on failure
 */
int checkDigit(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - converts string into integer
 * @str: string to convert to integer
 * Return: integer conversion output
 */
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}

/**
 * _itoa - converts integer to string
 * @n: integer to convert
 * Return: character mapped to integer
 */
char *_itoa(int n)
{
	char buff[10];
	int i = 0;

	if (n == 0)
		buff[i++] = '0';
	else
	{
		while (n > 0)
		{
			buff[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buff[i] = '\0';
	return (_strdup(buff));
}


/**
 * malloc_usable_size - Returns the usable size of
 * a dynamically allocated memory block.
 * @ptr: Pointer to the memory block whose usable size is to be determined.
 * Return: The usable size of the memory block, or 0 if @ptr is NULL.
 */
size_t malloc_usable_size(void *ptr)
{
return (malloc_usable_size(ptr));
}

/**
 * _realloc - Reallocates a memory block with a new size.
 * @ptr: Pointer to the previously allocated memory block.
 * @new_size: New size (in bytes) for the memory block.
 * Return: Pointer to the reallocated memory block,
 * or NULL if allocation fails.
 */
void *_realloc(void *ptr, size_t new_size)
{
size_t old_size;
void *new_ptr;
size_t copy_size;

if (ptr == NULL)
return (malloc(new_size));

if (new_size == 0)
{
free(ptr);
return (NULL);
}
old_size = malloc_usable_size(ptr);
new_ptr = malloc(new_size);

if (new_ptr == NULL)
return (NULL);

copy_size = (new_size < old_size) ? new_size : old_size;
_memcpy(new_ptr, ptr, copy_size);
free(ptr);
return (new_ptr);
}

