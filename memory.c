#include "shell.h"

/**
 * freeSafe - free from memory
 * @ptr: pointer
 */
void freeSafe(void *ptr)
{
if (ptr != NULL)
{
free(ptr);
ptr = NULL;
}
}