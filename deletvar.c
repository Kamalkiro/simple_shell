#include "main.h"

/**
 * Deletvar - deletes an environnement variable
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
				free(envar);
				environ[i] = arguments[j];
				return 110;
			}
			i++;
		}
		j++;
	}
	return 3;
}
void deletvaratparent(char *line)
{
	char *var = _calloc(MAXSIZE), *envar, *cline = _calloc(MAXSIZE);
	char **vars = NULL;
	int i = 0, len, j = 1;

	vars = malloc(MAXSIZE * sizeof(char *));
	_strcpy(cline, line, _strlen(line));
	var = _strtok(cline," \t");
	while(*var)
	{
		vars[i] = var;
		var = _strtok(NULL, " \t");
		i++;
	}
	vars[i] = NULL;
	i = 0;
	while(vars[j])
	{
		len = _strlen(vars[j]);
		while (environ[i] != NULL)
		{
			envar = _calloc(len);
			_strcpy(envar, environ[i], len);
			if (_strcmp(envar, vars[j]) == 0)
			{
				if (environ[i + 1] == NULL)
					environ[i] = NULL;
				else
				{
					while (environ[i])
					{
						environ[i] = environ[i + 1];
						i++;
					}
				}
				free(envar);
				break;
			}
			free(envar);
			i++;
		}
		i = 0;
		j++;
	}
	free(vars);
}