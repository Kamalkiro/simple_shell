#include "main.h"
/**
 * childprocess - starts a process after getting a command
 * @command: command to process with arguments
 * @count: number of arguments
 * Return: exit status
*/
int childprocess(char *command, int count)
{
	char **args = NULL;
	char *narg, *dflag;
	int i = 0, j = 0, flag = 0;
	int (*fp)(char **);

	if (*command == '\n' || count == 0)
		return (0);
	if (count > 1000)
	{
		count -= 1000;
		flag++;
	}
	args = malloc(sizeof(char *) * count);
	narg = _strtok(command, " \t");
	while (*narg)
	{
		args[i] = _calloc(120);
		args[i] = narg;
		narg = _strtok(NULL, " \t");
		i++;
	}
	args[i] = NULL;
	spacesback(args);
	if (flag == 1)
	{
		dflag = checkals(args[0]);
		args[0] = dflag;
		dflag = checkals(args[0]);
		if (dflag)
			args[0] = dflag;
	}
	args[0] = _strtok(args[0], " \'");
	if (_strchr(args[0], ' ') != 0)
	{
		args[i + 1] = NULL;
		while (i > 1)
		{
			args[i] = args[i - 1];
			i--;
		}
		args[0] = _strtok(args[0], " ");
		args[1] = _strtok(NULL, " ");
	}
	fp = structchoice(args[0]);
	j = fp(args);
	if (j == 2)
	{
		args[0] = prepareforexec(args[0]);
		if (args[0] == NULL)
			perror("command doesn't exist");
		if (execve(args[0], args, environ) == -1)
		{
			j = 3;
			perror("at execve");
		}
	}
	free(args);
	return (j);
}