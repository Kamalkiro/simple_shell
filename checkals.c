#include "main.h"

/**
 * checkals - checks if alias exists
 * @als: alias
 * Return: its value
*/

char *checkals(char *als)
{
	int fd = open(".aliases", O_RDONLY);
	char *line = _calloc(MAXSIZE), *each, *alx = _calloc(sizeof(als)), *ret;

	_strcpy(alx, als, MAXSIZE);
	read(fd, line, MAXSIZE);
	close(fd);
	each = _strtok(line, "=");
	while (*each)
	{
		if (_strcmp(each, alx) == 0)
		{
			free(alx);
			ret = _calloc(_strlen(each) + 1);
			each = _strtok(NULL, "\'\n");
			_strcpy(ret, each, _strlen(each));
			free(line);
			return (ret);
		}
		each = _strtok(NULL, "\n");
		each = _strtok(NULL, "=");
	}
	free(alx);
	free(line);
	return (NULL);
}
