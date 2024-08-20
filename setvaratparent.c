#include "main.h"

/**
 * setvaratparent - handles environ in parent process
 * @line: input
*/

void setvaratparent(char *line)
{
	char *key, *value;

	key = _strtok(line, " ");
	key = _strtok(NULL, " ");
	value = _strtok(NULL, " ");
	_setenv(key, value, 1);
}
