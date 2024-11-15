#include "main.h"

/**
 * changeiffromparent - changes directory from parent
 * @line: input
*/
void changeiffromparent(char *line)
{
	char *dir = _calloc(sizeof(char) * _strlen(line)), *tmp = dir;
	char *home = _getenv("HOME");
	int i = 0, j = 0, flag = 0;
	char *oldpwd = _getenv("OLDPWD");
	char arr[] = "-";
	char lami[] = "..";
	char *parent = NULL;

	parent = getcwd(parent, MAXSIZE);
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		while (line[i] != ' ' && line[i] != '\t' && line[i])
			i++;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] != ' ' && line[i] != '\t' && line[i])
		{
			while (line[i] != ' ' && line[i] != '\t' && line[i])
			{
				if (line[i] == '\"' || line[i] == '\'')
				{
					flag++;
					i++;
				}
				if (line[i + 1] == ' ' && flag % 2 == 1)
					line[i + 1] = ',';
				dir[j] = line[i];
				i++;
				j++;
			}
			i = 0;
			while (dir[i])
			{
				if (dir[i] == ',')
					dir[i] = ' ';
				i++;
			}
			dir[j] = '\0';
		}
		break;
	}
	if (_strcmp(dir, arr) == 0)
		dir = oldpwd;
	if (!*dir)
		dir = home;
	if (dir == lami)
		dir = goback(parent);
	_setenv("OLDPWD", parent, 1);
	if (chdir(dir) == -1)
		perror("cd");
	free(parent);
	free(oldpwd);
	free(home);
	free(tmp);
}
