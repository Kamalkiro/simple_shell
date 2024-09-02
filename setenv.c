#include "main.h"

/**
 * _setenv - handles the environnement variables
 * @var: The variable that we intend to change or create
 * @value: Its value
 * @signal: signal sent to determine whether to overwrite it if created
 * Return: 0 on success 1 if failed
*/
int _setenv(char *var, char *value, int signal)
{
	char *envar = NULL;
	char *modifvar, *hold;
	int i = 0, len = _strlen(var);

	if (!*var || !*value || signal > 1 || signal < 0)
		return (1);
	while (environ[i])
	{
		envar = _calloc(len + 1);
		_strcpy(envar, environ[i], len);
		if (_strcmp(envar, var) == 0)
		{
			free(envar);
			if (signal == 1)
			{
				modifvar = _strconcat(var, "=", _strlen(var) + 1);
				hold = modifvar;
				modifvar = _strconcat(modifvar, value, _strlen(value));
				free(hold);
				free(environ[i]);
				environ[i] = modifvar;
				return (0);
			}
			else
				return (1);
		}
		free(envar);
		i++;
	}
	modifvar = _strconcat(var, "=", _strlen(var) + 1);
	hold = modifvar;
	modifvar = _strconcat(modifvar, value, _strlen(value));
	free(hold);
	free(environ[i]);
	environ[i] = modifvar;
	environ[i + 1] = NULL;
	return (0);
}
