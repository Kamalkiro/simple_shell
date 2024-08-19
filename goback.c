#include "main.h"

/**
 * goback - goes to the previous directory
 * @current: current directory
 * Return: parent directory
*/

char *goback(char *current)
{
	char *tmp = current;

	while (*current)
		current++;
	current--;
	while (*current != '/')
	{
		*current = '\0';
		current--;
	}
	return (tmp);
}
