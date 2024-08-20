#include "main.h"

/**
 * deletvaratparent - deletes environement var at parent process
 * @line: input from user
*/
void deletvaratparent(char *line)
{
	char *var = _calloc(MAXSIZE), *envar, *cline = _calloc(MAXSIZE);
	char **vars = malloc(MAXSIZE * sizeof(char *));
	int i = 0, len, j = 1, x = 0;

	_strcpy(cline, line, _strlen(line));
	var = _strtok(cline, " \t");
	while (*var)
	{
		vars[x] = var;
		var = _strtok(NULL, " \t");
		x++;
	}
	vars[x] = NULL;
	while (vars[j])
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
				break;
			}
			i++;
		}
		i = 0;
		j++;
	}
	free(vars);
}
