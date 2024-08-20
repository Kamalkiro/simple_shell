#include "main.h"

/**
 * singinthandl - handles crtl + c
 * @s: signal
*/

void singinthandl(int s)
{
	char *dir = _calloc(MAXSIZE);
	int dirsize = MAXSIZE;

	if (s)
	{
		getcwd(dir, dirsize);
		_puts("\n");
		_puts(dir);
		_puts("$ ");
		fflush(stdout);
	}
}
