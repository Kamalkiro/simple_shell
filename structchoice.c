#include "main.h"

/**
 * structchoice - chooses the builtin cmd and returns its execution function
 * @command: the command to be checked if it was a builtin command
 * Return: a pointer to the appropriate function
*/
int (*structchoice(char *command))(char **)
{
    choice builtins[] = {
        {"cd", changedirectory},
        {"exit", goout},
        {"pwd", getdir},
        {"setenv", setvar},
        {"unset", deletvar},
        {"alias", setals},
        {"unalias", deletals},
        {NULL, notbuilt},
    };
    int i = 0, j = 0;
    
    while (builtins[i].choix)
    {
        j = _strcmp(command, builtins[i].choix);
        if (j == 0)
        {
            return(builtins[i].fp);
        }
        i++;
    }
    return (builtins[i].fp);
}