#include "main.h"

/**
 * Deletals - deletes an alias
 * @arguments: Input
 * Return: 109 as a signal for the alias to be deleted in parent process
*/
int deletals(char **arguments)
{
	int fd = open(".aliases", O_RDWR), i = 1, j = 0, x, z, y = 1;
	char *line = _calloc(MAXSIZE * 8), *each, *key;

	read(fd, line, MAXSIZE * 8);
	close(fd);
	while (arguments[i])
	{
		key = _calloc(strlen(arguments[i]));
		_strcpy(key, arguments[i], strlen(arguments[i]));
		_strtok(key, "=");
		j = 0;
		while(line && j < _strlen(line))
		{
			each = _calloc(_strlen(line));
			x = 0;
			while (line[j] != '=' && line[j])
			{
				each[x] = line[j];
				j++;
				x++;
			}
			each[x] = '\0';
			if (_strcmp(each, key) == 0)
			{
				y--;
				j -= x;
				while(line[j] != '\n')
				{
					z = j;
					while (line[z])
					{
						line[z] = line[z + 1];
						z++;
					}
				}
				while(line[j])
				{
					line[j] = line[j + 1];
					j++;
				}
				break;
			}
			while (line[j] != '\n' && line[j])
				j++;
			j++;
			free(each);
		}
		free(key);
		i++;
	}
	fd = open(".aliases", O_WRONLY | O_TRUNC);
	write(fd, line, _strlen(line));
	free(line);
	close(fd);
	return (y == 1 ? 3 : 0);
}