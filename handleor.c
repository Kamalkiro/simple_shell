#include "main.h"

/**
 * handleor - handles logical and or
 * @line: input
 * Return: 0 if nthn 1 if and 2 if or
*/
int handleor(char *line)
{
	int i = 0, ret = 0;

	if (line[i] == '|')
		ret = 2;
	if (line[i] == '&')
		ret = 1;
	return (ret);
}
