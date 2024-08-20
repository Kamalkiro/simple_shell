#include "main.h"

/**
 * _getline - reads a line from stdin
 * @buffer: string from stdin
 * @buffersize: sizeof string
 * @fd: file descriptor where it would get the line from
 * Return: characters read or -1 if it fails or encounters EOF
*/
int _getline(char **buffer, int *buffersize, int fd)
{
	char *line = _calloc(MAXSIZE);
	ssize_t size = read(fd, line, MAXSIZE);

	if (size == 0)
		return (-1);
	line[size - 1] = '\0';
	*buffer = line;
	*buffersize = size;
	return (size);
}
