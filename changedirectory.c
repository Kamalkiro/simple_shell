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
	char arr[] = "-";
	char lami[] = "..";
	char *parent = NULL;

	parent = getcwd(parent, MAXSIZE);
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
		return 0;
	}	
	return (113);
}
void changeiffromparent(char *line)
{
	char *dir = malloc(sizeof(char) * _strlen(line));
	int i = 0, j = 0;
	char *oldpwd = _getenv("OLDPWD");
	char arr[] = "-";
	char lami[] = "..";
	char *parent = NULL;

	parent = getcwd(parent, MAXSIZE);
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		while (line[i] != ' ' && line[i] != '\t' && line[i])
			i++;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] != ' ' && line[i] != '\t' && line[i])
		{
			while (line[i] != ' ' && line[i] != '\t' && line[i])
			{
				dir[j] = line[i];
				i++;
				j++;
			}
			dir[j] = '\0';
		}
		break;
	}
	if (_strcmp(dir, arr) == 0)
		dir = oldpwd;
	if (dir == lami)
	{
		dir = goback(parent);
	}
	_setenv("OLDPWD", parent, 1);
	if (chdir(dir) == -1)
		perror("cd");
}
char *goback(char *current)
{
	char *tmp = current;

	while (*current)
		current++;
	current--;
	while (*current != '/')
	{
		*current = '\0';
		current--;
	}
	return (tmp);
}

