#include "main.h"

/**
 * spacemv - moves out the trailing spaces
 * @str: string where spaces should be removed
  */

void spacemv(char *str)
{
    int y = _strlen(str) - 1;

    while (y > 0)
    {
        if (str[y] == ' ' || str[y] == '\n' || str[y] == '\t')
            str[y] = '\0';
        else
            break;
        y--;
    }
}