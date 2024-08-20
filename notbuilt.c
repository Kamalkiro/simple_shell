#include "main.h"

/**
 * notbuilt - informs childprocess that the command is not a built in
 * @arguments: Unused parameter just to be able to handle the function pointer
 * Return: 2 to be able to handle execve bcz args[0] is not a built-in
*/

int notbuilt(char **arguments __attribute__((unused)))
{
	return (2);
}
