#include "main.h"

/**
 * _strlen - counts the number of chars in a string
 * @s: string to be counted
 * Return: number of chars
*/

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}

	return (i);
}
