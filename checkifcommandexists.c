#include "main.h"

/**
 * checkifcommandexists - check if command exists or not
 * @line: input from stdin
 * Return: 1 if exists, 0 if not
*/
int checkifcommandexists(char *line)
{
	int i = 0, j = 0;
	char *command = malloc(MAXSIZE), *checkexec;
	choice builtins[] = {
        	{"cd", changedirectory},
        	{"exit", goout},
        	{"pwd", getdir},
        	{"setenv", setvar},
        	{"unset", deletvar},
        	{"alias", setals},
        	{"unalias", deletals},
        	{NULL, notbuilt},
	};

	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (line[i] != ' ' && line[i] != '\t' && line[i])
	{
		command[j] = line[i];
		i++;
		j++;
	}
	command[j] = '\0';
	i = 0;
	while (builtins[i].choix)
	{
        	j = _strcmp(command, builtins[i].choix);
        	if (j == 0)
        	{
			free(command);
			return (1);
        	}
		i++;
	}
	checkexec = prepareforexec(command);
	free(command);
	if (checkexec != NULL)
		return (1);
	else
		return (0);
}