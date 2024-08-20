#include "main.h"

/**
 * convertvar - converts the name of a variable into its value
 * @line: input
 * Return: line after converting variable into its value
*/
char *convertvar(char *line)
{
	int i = 0, j = 0, x;
	char *name = NULL, *cont = NULL;
	char *modif = NULL, *value = NULL;

	while (line[i] != '$')
		i++;
	x = i;
	i++;
	name = _calloc(_strlen(line) - i);
	while (line[i] != ' ' && line[i])
	{
		name[j] = line[i];
		i++;
		j++;
	}
	name[j] = '\0';
	value = _getenv(name);
	if (!value)
		return (line);
	j = 0;
	if (line[i] != '\0')
	{
		if (_strlen(line) - i > 1)
		{
			cont = _calloc(_strlen(line) - i + 1);
			while (line[i])
			{
				cont[j] = line[i];
				j++;
				i++;
			}
			cont[j] = '\0';
		}
	}
	while (line[x])
	{
		line[x] = '\0';
		x++;
	}
	modif = _calloc(_strlen(line) + _strlen(value) + _strlen(cont) + 1);
	if (*line)
	{
		modif = _strcpy(modif, line, _strlen(line));
		modif = _strconcat(modif, value, _strlen(value));
	}
	else
		modif = _strcpy(modif, value, _strlen(value));
	if (cont)
		modif = _strconcat(modif, cont, _strlen(cont));
	line = modif;
	return (line);
}
