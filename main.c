#include "main.h"

/**
 * main - main function for the shell
 * @ac: number of args
 * @av: double pointer to arguments
 * @env: instead of **environ
 * Return: 0 on success:
*/
void singinthandl(int s){
	char *dir = malloc(MAXSIZE);
	int dirsize = MAXSIZE;

	if(s)
	{
		getcwd(dir, dirsize);
		_puts("\n");
		_puts(dir);
		_puts("$ ");
		fflush(stdout);
		free(dir);
	}
}
int main(int ac, char **av __attribute__((unused)))
{
	size_t linesize; 
	unsigned int dirsize;
	char *line, *dir;
	int pid = 0, count, i = 0, status, e, ec = 0, characters, check;
	
	(void) ac;
	dirsize = MAXSIZE;

	while(1)
	{
parent:
		if (isatty(0))
		{
			dir = malloc(sizeof(char *) * MAXSIZE);
			getcwd(dir, dirsize);
			_puts(dir);
			free(dir);
			_puts("$ ");
		}
		signal(SIGINT, singinthandl);
		characters = getline(&line, &linesize, stdin);
		if (characters == -1)
		{
			if (isatty(0))
				_puts("\n");
			break;
		}
		spacemv(line);
		count = argcount(line);
		check = checkifcommandexists(line);
		if (check == 0)
		{
			if(!isatty(0))
			{
				_perror(av[0], av[1] ? av[1] : "Not found");
				goto parent;
			}
			else
			{
				_perror("at hsh", "command doesn't exist");
				goto parent;
			}	
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				i = childprocess(line, count);
				exit (i);
			}
			else
			{
				wait(&status);
				e = (status >> 8) & 0xFF;
				if (e == 110)
					deletvaratparent(line);
				if (e == 111)
					setvaratparent(line, count);
				if (e == 112)
					break;
				if (e == 113)
					changeiffromparent(line);
				if (e == 114)
				{
					ec = getexitcode(line);
					break;
				}
			}
		}
	}
	exit(ec ? ec : 0);
}
