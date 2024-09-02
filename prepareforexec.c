#include "main.h"

/**
 * prepareforexec - prepares the argument to be executed by getting its path
 * @command: the command argument
 * Return: the full path to the command
*/

char *prepareforexec(char *command)
{
	char *pathenv = _getenv("PATH");
	char *paths = _calloc(MAXSIZE * 8), *ppath, *tmp, *hold;

	if(!pathenv)
		return(NULL);
	_strcpy(paths, pathenv, MAXSIZE * 8);
	free(pathenv);
	ppath = _strtok(paths, ":");
	if (access(command, F_OK) == 0)
	{
		free(paths);
		return (command);
	}
	while (*ppath)
	{
		tmp = _strconcat(ppath, "/", 1);
		hold = _strconcat(tmp, command, 30);
		free(tmp);
		if (access(hold, F_OK) == 0)
		{
			free(paths);
			return (hold);
		}
		free(hold);
		ppath = (_strtok(NULL, ":"));
	}
	free(paths);
	return (NULL);
}
