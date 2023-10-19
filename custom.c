#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * custom_specifier - custom specifiers
 * @args: args
 * @c: characters
 * @buffer: buffer
 * @tb: total_bytes
 * @b: bytes
 * Return: bytes
 */
int custom_specifier(va_list args, char c, char *buffer, int *tb, int *b)
{
int error = 0;
if (c == 'b')
error = build_bin(va_arg(args, unsigned long), buffer, tb, b);
else if (c == 'R')
error = roT13(va_arg(args, char *), buffer, tb, b);
else if (c == 'S')
{
char *s = va_arg(args, char *);
if (s == NULL)
return (-1);
error = handle_non_printable(s, buffer, tb, b);
}
else if (c == 'r')
{
char *c = va_arg(args, char *);
char *t = (char *)malloc(sizeof(char) * (_straff(c) + 1));
if (t == NULL)
return (-1);
_strcpy(t, c);
reverse(t);
error = build_str(t, buffer, tb, b);
free(t);
}
if (error == -1)
return (-1);
return (0);
}
/**
 * build_bin - binary
 * @n: int
 * @buffer: buffer
 * @tb: total_bytes
 * @b: bytes
 * Return: int
 */
int build_bin(unsigned int n, char *buffer, int *tb, int *b)
{
char *bin;
int len, error = 0;
bin = convert(n, 2);
if (bin == NULL)
return (-1);
len = _straff(bin);
if (len > (BUF_CAPACITY - *b))
error = overflow(buffer, tb, b);
if (error == -1)
{
free(bin);
return (-1);
}
error = build_str(bin, buffer, tb, b);
free(bin);
if (error == -1)
return (-1);
return (0);
}
/**
 * handle_non_printable - non printable
 * @s: string
 * @buffer: buffer
 * @tb: total_bytes
 * @b: bytes
 * Return: int
 */
int handle_non_printable(char *s, char *buffer, int *tb, int *b)
{
int error = 0;
if (s == NULL)
return (-1);
while (*s != '\0')
{
if (*s < 32 || *s > 126)
{
if (*b + 4 > BUF_CAPACITY)
error = overflow(buffer, tb, b);
if (error != -1)
{
error = dectohexa(*s, buffer, b);
if (error == -1)
return (-1);
}
else
return (-1);
}
else
{
if (*b + 1 > BUF_CAPACITY)
error = overflow(buffer, tb, b);
if (error != -1)
buffer[(*b)++] = *s;
else
return (-1);
}
s++;
}
return (0);
}
