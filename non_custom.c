#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
/**
 * non_custom_specifier -handle non specifier
 * @args: arguments
 * @c: character
 * @buffer: buffer
 * @tb: tota_ bytes
 * @b: bytes
 * Return: int
 */
int non_custom_specifier(va_list args, char c, char *buffer, int *tb, int *b)
{
int err = 0;
if (c == 'c')
{
unsigned char t = va_arg(args, int);
buffer[(*b)++] = t;
}
else if (c == 's')
err = build_str(va_arg(args, char *), buffer, tb, b);
else if (c == 'i' || c == 'd')
err = build_int(va_arg(args, long), buffer, tb, b);
else if (c == 'u')
err = unsigned_int(va_arg(args, unsigned int), buffer, tb, b, c);
else if (c == 'o')
err = unsigned_int(va_arg(args, unsigned int), buffer, tb, b, c);
else if (c == 'x' || c == 'X')
err = convert_tohex(va_arg(args, unsigned int), c, buffer, b, tb);
if (*b > BUF_CAPACITY && err != -1)
err = overflow(buffer, tb, b);
if (err == -1)
return (-1);
return (0);
}
/**
 * handle_int - integers
 * @n: integer
 * @buffer: buffer
 * @tb: total bytes
 * @b: bytes
 * Return: int
 */
int build_int(int n, char *buffer, int *tb, int *b)
{
char *int_str = convert_int(n);
int len, error = 0;
if (int_str == NULL)
return (-1);
len = _straff(int_str);
if (len > (BUF_CAPACITY - *b))
error = overflow(buffer, tb, b);
if (error == -1)
{
free(int_str);
return (-1);
}
error = build_str(int_str, buffer, tb, b);
free(int_str);
if (error == -1)
return (-1);
return (0);
}
/**
 * build_str - build string
 * @s: string
 * @buffer: buffer
 * @tb: total bytes
 * @b: bytes
 * Return: void
 */
int build_str(char *s, char *buffer, int *tb, int *b)
{
int s_len, error = 0;
if (s == NULL)
s = "(null)";
s_len = _straff(s);
if (s_len > (BUF_CAPACITY - *b))
error = overflow(buffer, tb, b);
if (error == -1)
return (-1);
while (*s != '\0')
{
buffer[(*b)++] = *s;
s++;
}
return (0);
}
/**
 * unsigned_int - builds integers
 * @n: integer
 * @buff: buffer
 * @tb: total bytes
 * @b: bytes
 * @t: type
 * Return: void
 */
int unsigned_int(unsigned int n, char *buff, int *tb, int *b, char t)
{
char *int_str = t == 'o' ? convert(n, 8) : convert_unsigned_int(n);
int len, error = 0;
if (int_str == NULL)
return (-1);
len = _straff(int_str);
if (len > (BUF_CAPACITY - *b))
error = overflow(buff, tb, b);
if (error == -1)
{
free(int_str);
return (-1);
}
error = build_str(int_str, buff, tb, b);
free(int_str);
if (error == -1)
return (-1);
return (0);
}
