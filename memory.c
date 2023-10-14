#include "shell.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory block to reallocate
 * @oldSize: size of the currently allocated memory block
 * @newSize: new size to reallocate the memory block to
 * Return: pointer to the reallocated memory block
 */
void *_realloc(void *ptr, unsigned int oldSize, unsigned int newSize)
{
	void *newPtr;

	if (newSize == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		newPtr = malloc(newSize);
		return (newPtr);
	}
	if (newSize <= oldSize)
		return (ptr);
	newPtr = malloc(newSize);
	if (newPtr == NULL)
		return (NULL);
	_memcpy(newPtr, ptr, oldSize);
	free(ptr);
	return (newPtr);
}

/**
 * _freeAll - free allocated memory
 * @cmd: array pointer
 * @l: char pointer
 * Return: nothing
 */
void _freeAll(char **cmd, char *l)
{
	free(cmd);
	free(l);
	cmd = NULL;
	l = NULL;
}

/**
 * _calloc - allocates array memory
 * @s: block size
 * Return: pointer
 */
void *_calloc(unsigned int s)
{
	char *arr;
	unsigned int i;

	if (s == 0)
		return (NULL);
	arr = malloc(s);
	if (arr == NULL)
		return (NULL);
	for (i = 0; i < s; i++)
	{
		arr[i] = '\0';
	}
	return (arr);
}


/**
 * _memcpy - copies n bytes of memory
 * @dest: destination pointer
 * @src: source pointer
 * @n: count of bytes to copy
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _memset - fills memory with constant char
 * @s: pointer to by s
 * @b: constant char
 * @n: number of bytes to fill
 * Return: pointer to s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
