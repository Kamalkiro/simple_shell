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
	char *envar = malloc(MAXSIZE);
	char *modifvar;
	int i = 0, len = _strlen(var);
	if (!var || !value || signal > 1 || signal < 0)
		return 1;
	while (environ[i])
	{
		_strcpy(envar, environ[i], len);
		if (_strcmp(envar, var) == 0)
		{
			if (signal == 1)
			{
				modifvar = malloc(_strlen(var) + 1 + _strlen(value) + 1);
				modifvar = _strconcat(modifvar, var, _strlen(var));
				modifvar = _strconcat(modifvar, "=", 1);
				modifvar = _strconcat(modifvar, value, _strlen(value));
				environ[i] = modifvar;
				return 0;
			}
			else
				return 1;
		}
		i++;
	}
	modifvar = malloc(_strlen(var) + 1 + _strlen(value) + 1);
	modifvar = _strconcat(modifvar, var, _strlen(var));
	modifvar = _strconcat(modifvar, "=", 1);
	modifvar = _strconcat(modifvar, value, _strlen(value));
	environ[i] = modifvar;
	environ[i + 1] = NULL;
	free(envar);
	return 0;
}
