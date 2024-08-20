#include "main.h"

/**
 * _strconcat - concatenates a string
 * @first: string to be concatenated
 * @second: string of chars to be added to the first
 * @n: number of bytes to be added
 * Return: a pointer to the new string
*/
char *_strconcat(char *first, char *second, int n)
{
	char *tmp = NULL, *ret;

	if (n > _strlen(second))
		ret = _calloc(_strlen(first) + _strlen(second) + 1);
	else
		ret = _calloc(_strlen(first) + n + 1);
	if (!first || !second || n == 0)
		return (NULL);
	_strcpy(ret, first, _strlen(first));
	tmp = ret;
	while (*ret)
		ret++;
	_strcpy(ret, second, n);
	while (*ret)
		ret++;
	*ret = '\0';
	ret = tmp;
	return (ret);
}
