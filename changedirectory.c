#include "main.h"

/**
 * changedirectory - changes directory
 * @arguments: the argument after cd should be the path to the new directory
 * Return: a signal of 113 as an exit value for the parent to change directory
*/

int changedirectory(char **arguments)
{
	char *dir = arguments[1];
	char *oldpwd = _getenv("OLDPWD");
	char *home = _getenv("HOME");
	char arr[] = "-";
	char lami[] = "..";
	char *parent = NULL;

	parent = getcwd(parent, MAXSIZE);
	if (dir == NULL)
		dir = home;
	if (_strcmp(dir, arr) == 0)
	{
		dir = oldpwd;
	}
	if (dir == lami)
	{
		char *parent = NULL;

		parent = getcwd(parent, MAXSIZE);
		dir = goback(parent);
	}
	_setenv("OLDPWD", parent, 1);
	if (chdir(dir) == -1)
	{
		perror("cd");
		return (3);
	}
	free(parent);
	return (113);
}
