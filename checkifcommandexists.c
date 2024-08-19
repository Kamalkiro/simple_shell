#include "main.h"

/**
 * checkifcommandexists - check if command exists or not
 * @line: input from stdin
 * Return: 2 if alias 1 if exists, 0 if not
*/
int checkifcommandexists(char *line)
{
	int i = 0, j = 0, ret = 0;
	char *command = _calloc(MAXSIZE), *checkexec = NULL, *check = NULL, *cmd;
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
	cmd = _calloc(_strlen(command) + 1);

	_strcpy(cmd, command, _strlen(command));
	cmd[_strlen(command)] = '\0';
	free(command);
	check = checkals(cmd);
	if (check)
	{
		free(cmd);
		cmd = check;
		check = checkals(cmd);
		if (check)
			cmd = check;
		ret = 1;
	}
	cmd = _strtok(cmd, " \'");
	i = 0;
	while (builtins[i].choix)
	{
		j = _strcmp(cmd, builtins[i].choix);
		if (j == 0)
			return (ret + 1);
		i++;
	}
	checkexec = prepareforexec(cmd);
	if (checkexec != NULL)
		ret += 1;
	else
		ret = 0;
	return (ret);
}