#include "main.h"

/**
 * handlechain - handles chained commands
 * @line: chain of commands
 * Return: array of commands
*/
char **handlechain(char *line)
{
	int i = 0, j = 0, a = 0;
	char **commands = NULL, *command = NULL;

	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = ';';
		if (line[i] == '&' || line[i] == '|')
		{
			line[i] = ';';
			i++;
		}
		i++;
	}
	j = _strchr(line, ';');
	if (j > 0)
		commands = malloc(sizeof(char *) * (j + 2));
	else
		return (NULL);
	j = 0;
	while (line[j])
	{
		i = 0;
		command = _calloc(_strlen(line));
		while (line[j] != ';' && line[j])
		{
			command[i] = line[j];
			j++;
			i++;
		}
		command[i] = '\0';
		commands[a] = _calloc(_strlen(command + 1));
		_strcpy(commands[a], command, MAXSIZE);
		free(command);
		a++;
		if (line[j])
			j++;
	}
	commands[a] = NULL;
	return (commands);
}
