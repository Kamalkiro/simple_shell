#include "main.h"

/**
 * _puts - prints a string
 * @chars: string to be printed
 */
void _puts(char *chars)
{
	char *tmp = chars;

	while (*chars)
	{
		write(1, chars, 1);
		chars++;
	}
	chars = tmp;
}

