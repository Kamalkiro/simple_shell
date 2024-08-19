#include "main.h"

/**
 * spacesback - turns _ into space after tokenization
 * @args: tokenized arguments
*/
void spacesback(char **args)
{
	int i = 0, j;

	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == ',')
				args[i][j] = ' ';
			j++;
		}
		i++;
	}
}