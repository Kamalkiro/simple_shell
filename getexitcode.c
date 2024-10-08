#include "main.h"

/**
 * getexitcode - gets the exit code if entered
 * @line: line entered with an exit code
 * Return: exit code after converting it to int
*/
int getexitcode(char *line)
{
	int i = 0, j = 0, ret = 0, flag = 1;
	char *code = _calloc(sizeof(char) * _strlen(line));

	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (line[i] != ' ' && line[i] != '\t' && line[i])
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '-')
	{
		flag = -1;
		i++;
	}
	if (line[i] != ' ' && line[i] != '\t' && line[i])
	{
		while (line[i] != ' ' && line[i] != '\t' && line[i])
		{
			code[j] = line[i];
			i++;
			j++;
		}
		code[j] = '\0';
	}
	i = 0;
	while (code[i])
	{
		ret = (ret * 10) + (code[i] - 48);
		i++;
	}
	free(code);
	return (ret * flag);
}
