#include "main.h"

/**
 * _strtok - tokenizes a string
 * @line: string from stdin to be tokenized
 * @delim: delimiter of tokenization
 * Return: new string
*/
char *_strtok(char *line, char *delim)
{
	int i = 0, j, skip = 0, sskip = 0, x = 0, y = 0;
	char *ret;
	static char *str_ptr;

	if (line == NULL)
		line = str_ptr;
	str_ptr = line;
	while (line[i])
	{
		for (j = 0; delim[j]; j++)
		{
			if (line[i] == delim[j])
				skip++;
		}
		if (skip == sskip)
			break;
		i++;
		sskip = skip;
	}
	for ( ; x < skip; line++, x++)
		str_ptr++;
	while (line[y])
	{
		for (j = 0; delim[j]; j++)
		{
			if (line[y] == delim[j])
			{
				sskip = 113;
				line[y] = '\0';
				break;
			}
		}
		y++;
		if (sskip == 113)
			break;
	}
	ret = line;
	for (skip = 0; skip < y; skip++)
		str_ptr++;
	return (ret);
}
