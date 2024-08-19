#include "main.h"

/**
 * spacemv - moves out the trailing spaces, handles comments and quotes
 * @str: string where spaces should be removed
  */

void spacemv(char *str)
{
	int y = _strlen(str) - 1, i = 0, x = 1, flag = 0;

	while (y > 0)
	{
		if (str[y] == ' ' || str[y] == '\n' || str[y] == '\t')
			str[y] = '\0';
		else
			break;
		y--;
	}
	while (str[i])
	{
		if (str[i] == '#' && (str[i - 1] == ' ' || str[i - 1] == '\0'))
		{
			while(str[i])
			{
				str[i] = '\0';
				i++;
				y--;
			}
			y++;
		}
		i++;
	}
	i = 0;
	while(str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			flag++;
			while(str[i])
			{
				if (str[i + 1] == ' ' && (flag % 2) == 1)
					str[i + 1] = ',';
				if (str[i + 1] == '\'' || str[i + 1] == '\"')
				{
					x++;
					break;
				}
				str[i] = str[i + 1];
				i++;
			}
		}
		i++;
	}
	if (flag > 0)
		str[y + 1 - x] = '\0';
}