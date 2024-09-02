#include "main.h"

/**
 * goout - exits the shell
 * @arguments: Unused parameter added to handle the function pointer
 * Return: status 112 to exit.
  */

int goout(char **arguments)
{
	int i = 0, ret = 0;

	if (arguments[1])
	{
		while (arguments[1][i] && arguments[1][i] > 47 && arguments[1][i] < 58)
		{
			ret = (ret * 10) + (arguments[1][i] - 48);
			i++;
		}
		if ((arguments[1][i] > 57 || arguments[1][i] < 48) && arguments[1][i])
		{
			if (arguments[1][i] != '-')
				perror("non valid exit code");
			else
				return (114);
		}
		else
		{
			_setenv("EXITCODE", arguments[1], 1);
			return (114);
		}
	}
	else
		return (112);
	return (3);
}
