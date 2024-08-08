#include "main.h"

/**
 * _strcpy - copies a string
 * @first: string to be pasted into
 * @second: string of chars to be copied
 * @n: number of bytes to be copied
 * Return: a pointer to the first string
*/

char *_strcpy(char *first, char *second, int n)
{
	int i;

	if (n < 1 || !*second)
		return (NULL);
	for (i = 0; i < n && second[i]; i++)
	{
		first[i] = second[i];
	}
	first[i] = '\0';
	return (first);
}
