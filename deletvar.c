#include "main.h"

/**
 * deletvar - deletes an environnement variable
 * @arguments: tokenized input from user
 * Return: 110 as a signal to the parent to delete too -1 if its not set
*/
int deletvar(char **arguments)
{
	char *envar = _calloc(MAXSIZE);
	int i = 0, j = 1, len;

	while (arguments[j])
	{
		len = _strlen(arguments[j]);
		while (environ[i])
		{
			_strcpy(envar, environ[i], len);
			if (_strcmp(envar, arguments[j]) == 0)
			{
				environ[i] = arguments[j];
				return (110);
			}
			i++;
		}
		j++;
	}
	return (3);
}
