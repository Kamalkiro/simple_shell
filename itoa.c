#include "main.h"

/**
 * itoa - converts an int into a string
 * @num: int to be converted
 * Return: converted string
*/
char *itoa(int num)
{
	int i = 1000000000, j = 0, flag = 0;
	char *str = _calloc(7);

	if (num < 0)
	{
		num = -num;
		flag++;
	}
	while (num / i == 0 && i > 1)
		i /= 10;
	if (i == 0)
	{
		str[j] = 48;
		str[j + 1] = '\0';
		return (str);
	}
	if (flag > 0)
	{
		str[j] = '-';
		j++;
	}
	while (i > 0)
	{
		str[j] = num / i + 48;
		num %= i;
		i /= 10;
		j++;
	}
	str[j] = '\0';
	return (str);
}