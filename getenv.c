#include "main.h"

/**
 * _getenv - gets the value of a keyword in the environnement variable
 * @var: keyword
 * Return: value
*/

char *_getenv(char *var)
{
	int i = 0;
	char *tmp, **env = environ, *env_one;

	while (environ[i])
	{
		env_one = _calloc(MAXSIZE * 8);
		_strcpy(env_one, env[i], MAXSIZE * 8);
		tmp = _strtok(env_one, "=");
		if (_strcmp(tmp, var) == 0)
		{
			tmp = _strtok(NULL, "\0");
			return (tmp);
		}
		i++;
	}
	return (NULL);
}
