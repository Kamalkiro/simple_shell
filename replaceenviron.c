#include "main.h"

/**
 * replace_environ - replaces environ with a new allocated strings
*/
void replace_environ()
{
	int i = 0;
	char **replace = malloc(sizeof(char *) * MAXSIZE);

	while (environ[i])
	{
		replace[i] = _calloc(_strlen(environ[i] + 1));
		_strcpy(replace[i], environ[i], _strlen(environ[i]));
		i++;
	}
	environ = replace;
}
