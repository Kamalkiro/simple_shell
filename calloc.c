#include "main.h"

/**
 * _calloc - allocates and initalizes memory with /0 for a variable
 * @size: of memory to be allocated
 * Return: pointer to the allocated and initialized memory
*/
char *_calloc(int size)
{
	char *ptr;
	int i = 0;

	ptr = malloc(size);
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
