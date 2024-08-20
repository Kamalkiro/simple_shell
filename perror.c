#include "main.h"

/**
 * _perror - same as normal perror but the syntax follows alx rules
 * @argf: first argument
 * @args: second argument
*/
void _perror(char *argf, char *args)
{
	while (*argf != '\0')
	{
		write(2, argf, 1);
		argf++;
	}
	write(2, ": ", 2);
	while (*args)
	{
		write(2, args, 1);
		args++;
	}
	write(2, "\n", 1);
}
