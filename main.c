#include "main.h"

/**
 * main - main function for the shell
 * @ac: number of args
 * @av: double pointer to arguments
 * @env: instead of **environ
 * Return: 0 on success:
*/

int main(int ac, char **av)
{
	unsigned int dirsize;
	char *line = NULL, *dir, *vari, **commands = NULL;
	int pid = 0, count, i = 0, status, e, ec = 0, characters;
	int check, linesize, ppid = 0, x = 0, fd, stepout = 0, flag = 0;

	(void) ac;
	dirsize = MAXSIZE;
	ppid = getpid();
	vari = itoa(ppid);
	_setenv("$", vari, 1);
	if (av[1])
	{
		fd = open(av[1], O_RDONLY);
		line = _calloc(MAXSIZE * 8);
		check = read(fd, line, MAXSIZE * 8);
		if (check)
			commands = handlechain(line);
		stepout++;
		line = NULL;
	}
	while (1)
	{
		if (stepout && !commands)
			break;
parent:
		if (isatty(0) && !commands)
		{
			dir = _calloc(sizeof(char *) * MAXSIZE);
			getcwd(dir, dirsize);
			_puts(dir);
			_puts("$ ");
		}
		signal(SIGINT, singinthandl);
		if (!commands)
		{
			characters = _getline(&line, &linesize, 0);
		}
		if (characters == -1)
		{
			if (isatty(0))
				_puts("\n");
			break;
		}
		if (!commands)
			commands = handlechain(line);
		if (commands)
		{
			if (commands[x])
			{
				line = _calloc(_strlen(commands[x]) + 1);
				_strcpy(line, commands[x], MAXSIZE);
				x++;
			}
			if (!commands[x])
			{
				x = 0;
				free(commands);
				commands = NULL;
			}
		}
		if (handleor(line) != 0)
		{
			flag = handleor(line);
			if ((e == 3 && flag == 1) || (flag == 2 && e != 3))
			{
				continue;
			}
			line = _strtok(line, "|&");
		}
		spacemv(line);
		if (_strchr(line, '$') > 0)
		{
			line = convertvar(line);
		}
		count = argcount(line);
		check = checkifcommandexists(line);
		if (check == 0)
		{
			e = 3;
			if (!isatty(0))
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
			if (check == 2)
				count += 1000;
			pid = fork();
			if (pid == 0)
			{
				i = childprocess(line, count);
				exit(i);
			}
			else
			{
				wait(&status);
				e = (status >> 8) & 0xFF;
				vari = itoa(e);
				_setenv("?", vari, 1);
				if (e == 110)
					deletvaratparent(line);
				if (e == 111)
					setvaratparent(line);
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
	freedouble(to_free);
	exit(ec ? ec : 0);
}
