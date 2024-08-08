#include "main.h"

/**
 * argcount - counts number of arguments typed in stdin
 * @line: line provided in the stdin
 * Return: number of arguments
*/
int argcount(char *line)
{
	int ret = 0, i = 0;

	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] != ' ' && line[i] != '\t' && line[i])
		{
			ret++;
			while (line[i] != ' ' && line[i] != '\t' && line[i])
				i++;
		}
	}
	return (ret);
}
