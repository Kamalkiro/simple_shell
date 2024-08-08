#include "main.h"

/**
 * _getenv - gets the value of a keyword in the environnement variable
 * @var: keyword
*/

char *_getenv(char *var)
{
	int i = 0;
	char *tmp, **env = environ, *env_one;

	while(environ[i])
	{
		env_one = malloc(MAXSIZE);
		_strcpy(env_one, env[i], MAXSIZE);
		tmp = strtok(env_one, "=");
		if (_strcmp(tmp, var) == 0)
		{
			tmp = strtok(NULL, "\0");
			return(tmp);
		}
		free(env_one);
		i++;
	}
	return(NULL);
}