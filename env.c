#include "main.h"

/**
 * my_env - prints the environnement
 * @arguments: unused variable
 * Return: 0 on success
*/
int my_env(char **arguments __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		_puts("\n");
		i++;
	}
	return (i);
}
