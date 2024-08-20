#include "main.h"

/**
 * checkals - checks if alias exists
 * @als: alias
 * Return: its value
*/

char *checkals(char *als)
{
	int fd = open(".aliases", O_RDONLY), i = 0;
	char *line = _calloc(MAXSIZE), *each, *alx = _calloc(sizeof(als));

	_strcpy(alx, als, MAXSIZE);
	read(fd, line, MAXSIZE);
	close(fd);
	each = _strtok(line, "=");
	while (*each)
	{
		if (_strcmp(each, alx) == 0)
		{
			i++;
			each = _strtok(NULL, "\'\n");
			return (each);
		}
		each = _strtok(NULL, "\n");
		each = _strtok(NULL, "=");
	}
	return (NULL);
}
