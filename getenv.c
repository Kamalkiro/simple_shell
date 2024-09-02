#include "main.h"

/**
 * _getenv - gets the value of a keyword in the environnement variable
 * @var: keyword
 * Return: value
*/

char *_getenv(char *var)
{
	int i = 0;
	char *tmp, **env = environ, *env_one, *ret;

	while (environ[i])
	{
		env_one = _calloc(MAXSIZE * 8);
		_strcpy(env_one, env[i], MAXSIZE * 8);
		tmp = _strtok(env_one, "=");
		if (_strcmp(tmp, var) == 0)
		{
			tmp = _strtok(NULL, "\0");
			ret = _calloc(strlen(tmp) + 1);
			_strcpy(ret, tmp, _strlen(tmp));
			free(env_one);
			return (ret);
		}
		i++;
		free(env_one);
	}
	return (NULL);
}
