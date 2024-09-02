#include "main.h"

/**
 * convertvar - converts the name of a variable into its value
 * @line: input
 * Return: line after converting variable into its value
*/
char *convertvar(char *line)
{
	int i = 0, j = 0, x;
	char *name = NULL, *cont = NULL, *hold;
	char *modif = NULL, *value = NULL;

	while (line[i] != '$')
		i++;
	x = i;
	name = _calloc(_strlen(line) - i);
	for (i++; line[i] != ' ' && line[i]; i++, j++)
		name[j] = line[i];
	name[j] = '\0';
	value = _getenv(name);
	free(name);
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
	if (*line)
		modif = _strconcat(line, value, _strlen(value));
	else
	{
		modif = _calloc(_strlen(value) + 1);
		modif = _strcpy(modif, value, _strlen(value));
	}
	if (cont)
	{
		hold = modif;
		modif = _strconcat(modif, cont, _strlen(cont));
		free(hold);
		free(cont);
	}
	line = modif;
	free(value);
	return (line);
}
