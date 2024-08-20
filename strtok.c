#include "main.h"

/**
 * _strtok - tokenizes a string
 * @line: string from stdin to be tokenized
 * @delim: delimiter of tokenization
 * Return: new string
*/
char *_strtok(char *line, char *delim)
{
	int i = 0, j, skip = 0, sskip = 0;
	char *ret;
	static char *str_ptr;

	if (line == NULL)
		line = str_ptr;

	str_ptr = line;
	while (line[i])
	{
		j = 0;
		while (delim[j])
		{
			if (line[i] == delim[j])
			{
				skip++;
			}
			j++;
		}
		if (skip == sskip)
			break;
		i++;
		sskip = skip;
	}
	i = 0;
	while (i < skip)
	{
		line++;
		str_ptr++;
		i++;
	}
	i = 0;
	while (line[i])
	{
		j = 0;
		while (delim[j])
		{
			if (line[i] == delim[j])
			{
				sskip = 113;
				line[i] = '\0';
				break;
			}
			j++;
		}
		i++;
		if (sskip == 113)
			break;
	}
	ret = line;
	skip = 0;
	while (skip < i)
	{
		str_ptr++;
		skip++;
	}
	return (ret);
}
