#include "main.h"

/**
 * childprocess - starts a process after getting a command
 * @command: command to process with arguments
 * Return : exit status
*/
int childprocess(char *command, int count)
{
	char **args = NULL;
	char *narg;
	int i = 0, j = 0;
	int (*fp)(char **);

	if(*command == '\n')
		return 0;

    	args = malloc(MAXSIZE);
	narg = strtok(command," \t");
	while(narg)
	{
		args[i] = narg;
		narg = strtok(NULL, " \t");
		i++;
	}
	args[i] = NULL;
	fp = structchoice(args[0]);
	j = fp(args);
	if (j == 2)
	{
		args[0] = prepareforexec(args[0]);
		if (args[0] == NULL)
			perror("command doesn't exist");
		if (execve(args[0], args, environ) == -1)
		{
			perror("at execve");
		}
	}
	free(args);
	i = 0;
	return (j);
}