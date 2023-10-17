#include "main.h"
/**
 *print_char - print character
 *@c: param
 *Return: c
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}
