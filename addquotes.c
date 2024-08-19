#include "main.h"

/**
 * addquotes - adds quotes to the value printed of an alias
 * @arg: the line to be added into alias list
*/
void addquotes(char *arg)
{
	int i = 0, x = _strlen(arg);

	while (arg[i])
	{
		if (arg[i] == '=')
		{
			while (x > i)
			{
				arg[x + 1] = arg[x];
				x--;
			}
			arg[i + 1] = '\'';
		}
		i++;
	}
	arg[i] = '\'';
	arg[i + 1] = '\0';
}
