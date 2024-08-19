#include "main.h"

/**
 * prepareforexec - prepares the argument to be executed by getting its full path
 * @command: the command argument
 * Return: the full path to the command
*/

char *prepareforexec(char *command)
{
	char *pathenv = _getenv("PATH");
	char *paths = _calloc(MAXSIZE * 8), *ppath, *tmp;
	int i = 0;
	
	_strcpy(paths, pathenv, MAXSIZE * 8);
	ppath = _strtok(paths, ":");
	tmp = _calloc(120);
	if(access(command, F_OK) == 0)
		return (command);
	while (*ppath)
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
		ppath = (_strtok(NULL, ":"));
	}
	return(NULL);
}
