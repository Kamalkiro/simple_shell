#include "main.h"

/**
 * _strcmp - compares two strings
 * @first: first string
 * @second: second string
 * Return: 0 if equals, -1 if different
*/

int _strcmp(char *first, char *second)
{
	int i = 0;

	while (first[i] && second[i])
	{
		if (first[i] != second[i])
		{
			i = -2;
			break;
		}
		i++;
	}
	if (i < 1 || _strlen(first) != _strlen(second))
		return (-1);
	return (0);
}
