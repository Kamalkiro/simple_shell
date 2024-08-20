#include "main.h"

/**
 * _strchr - searches for a char in a string
 * @str: string to be searched
 * @chr: character to e found
 * Return: occurence of the character found
*/
int _strchr(char *str, char chr)
{
	int i = 0;

	while (*str && str)
	{
		if (*str == chr)
			i++;
		str++;
	}
	return (i);
}
