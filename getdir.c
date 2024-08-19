#include "main.h"

/**
 * getdir - prints the path to the current directory
 * @arguments: Unused param added just to handle the function pointer
 * Return: 0 on success
*/

int getdir(char **arguments __attribute__((unused)))
{
    size_t size = MAXSIZE;
    char *dir = _calloc(MAXSIZE);

    getcwd(dir, size);
    _puts(dir);
    _puts("\n");
    free(dir);
    return 1;
}