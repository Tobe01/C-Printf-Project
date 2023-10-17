#include "main.h"
/**
 * print_str - print string
 *@str: param
 *Return: count
 */
int print_str(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}
