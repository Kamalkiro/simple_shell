#include "main.h"

/**
 * setvar - exports a variable into the env
 * @arguments: tokenized input from user
 * Return: 111 as a signal to the parent to export too -1 if its not set
*/

int setvar(char **arguments)
{
	int check = 1;

	while (arguments[check])
	{
		check++;
	}
	if (check == 3)
	{
		_setenv(arguments[1], arguments[2], 1);
		return (111);
	}
	else
	{
		perror("Usage : setenv key value");
		return (3);
	}
	return (3);
}
