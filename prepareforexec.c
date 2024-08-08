#include "main.h"

/**
 * prepareforexec - prepares the argument to be executed by getting its full path
 * @command: the command argument
 * Return: the full path to the command
*/

char *prepareforexec(char *command)
{
	char *pathenv = _getenv("PATH");
	char *paths = malloc(MAXSIZE);
	int i = 0;
	
	
	_strcpy(paths, pathenv, MAXSIZE);
	char *ppath = strtok(paths, ":"), *tmp = malloc(MAXSIZE);

	while (ppath)
	{
		tmp = _strconcat(ppath, "/", 1);
		tmp = _strconcat(tmp, command, 30);
		tmp = _strconcat(tmp, "\0", 1);
		if(access(tmp, F_OK) == 0)
			{
				free(paths);
				return(tmp);
			}
		i--;
		ppath = (strtok(NULL, ":"));
	}
	return(NULL);
}
