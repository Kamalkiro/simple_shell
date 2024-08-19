#include "main.h"

/**
 * setals - sets an alias
 * @arguments: Input
 * Return: 108 as a signal for the alias to be set in parent process
*/
int setals(char **arguments)
{
        int fd, size, count = 0, i = 0, check = 0;
        char *aliases, *cheker, *modif, **modifier = malloc(sizeof(char *));

        fd = open(".aliases", O_CREAT | O_RDWR | O_APPEND,0666);
	while(arguments[i])
	{
		i++;
	}
	i--;
        if (arguments[1])
        {
		while (i > 0)
                {
			count = 0;
			check = 0;
			while(arguments[i][count])
			{
				if (arguments[i][count] == '=')
				{	
					check++;
				}
				count++;
			}
			if (check == 0)
			{
				cheker = checkals(arguments[i]);
				if (!cheker)
				{
					_perror("at alias", " non valid entry");
					return 3;
				}
				else
				{	
					_puts("alias ");
					_puts(arguments[i]);
					_puts("=");
					_puts("\'");
					_puts(cheker);
					_puts("\'");
					_puts("\n");
					i--;
				}
			}
			else
			{
				modifier[0] = NULL;
				modif = _calloc(_strlen(arguments[i]));
				modifier[1] = modif;
				modifier[2] = NULL;
				_strcpy(modif, arguments[i], MAXSIZE);
				deletals(modifier);
				free(modif);
				addquotes(arguments[i]);
				write (fd, arguments[i], _strlen(arguments[i]));
				write (fd, "\n", 1);
				i--;
			}
		}
        }
        else
        {
		aliases = _calloc(MAXSIZE);
                size = read(fd, aliases, MAXSIZE);

		aliases[size] = '\0';
                _puts(aliases);
                free(aliases);
        }
	free(modifier);
        close(fd);
        return 108;
}