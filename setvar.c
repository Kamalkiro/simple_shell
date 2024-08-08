#include "main.h"

/**
 * setvar - exports a variable into the env
 * @arguments: tokenized input from user
 * Return: 111 as a signal to the parent to export too -1 if its not set
*/

int setvar(char **arguments)
{
        int i = 0, j = 1, check = 1, signal = 0;

        while (arguments[check])
        {
                check++;
        }
        if (check > 1)
        {
                _setenv(arguments[1], arguments[2], 1);
		return 111;
        }
        else
        {
		perror("Usage : export key=value");
		return -1;
        }
        return -1;
}
void setvaratparent(char *line, int count)
{
        int i = 2;
        char *key, *value;
        while (*line == ' ' || *line == '\t')
		line++;
	while (*line != ' ' && *line != '\t' && *line)
		line++;
	while (*line == ' ' || *line == '\t')
		line++;
        key = strtok(line, " ");
        value = strtok(NULL, " ");
        _setenv(key, value, 1);
        if (count > 2)
        {
                while (i < count)
                {
                        key = strtok(NULL, " ");
                        value = strtok(NULL, " ");
                        _setenv(key, value, 1);
                        i++;
                }
        }
}