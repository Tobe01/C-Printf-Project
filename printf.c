#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * _printf - printf function
 * @ft: format
 * Return: int
 */
int _printf(const char *ft, ...)
{
va_list args;
int bytes = 0, total_bytes = 0, error = 0;
char buffer[BUF_CAPACITY];
if (ft == NULL)
return (-1);
va_start(args, ft);
while (*ft != '\0')
{
if (*ft == '%')
{
++ft;
if (*ft == '%')
buffer[bytes++] = *ft;
else if (*ft == 'c' || *ft == 's' || *ft == 'i' || *ft == 'd' || *ft == 'p')
error = none_standard_specifiers(args, *ft, buffer, &total_bytes, &bytes);
else if (*ft == 'b' || *ft == 'R' || *ft == 'S' || *ft == 'r')
error = standard_specifiers(args, *ft, buffer, &total_bytes, &bytes);
else if (*ft == '0' || *ft == '-' || *ft == '+' || *ft == '#' || *ft == ' ')
error = 0;
else if (*ft == 'l' || *ft == 'h')
error = 0;
else if (*ft == 'u' || *ft == 'o' || *ft == 'x' || *ft == 'X')
error = none_standard_specifiers(args, *ft, buffer, &total_bytes, &bytes);
else
error = handle_unknown(*ft, buffer, &total_bytes, &bytes);
}
else
error = none_specifiers(*ft, buffer, &total_bytes, &bytes);
if (error == -1)
return (exit_error(args));
ft++;
}
return (watch_data(args, buffer, total_bytes, bytes));
}
/**
 * watch_data - exits the program
 * @args: args
 * @buffer: buffer
 * @tb: total bytes
 * @b: bytes
 * Return: int
 */
int watch_data(va_list args, char *buffer, int tb, int b)
{
int error = write(1, buffer, b);
va_end(args);
if (error == -1)
return (-1);
return (tb + b);
}
/**
 * exit_error - exits
 * @args: args
 * Return: int
 */
int exit_error(va_list args)
{
va_end(args);
return (-1);
}
/**
 * handle_unknown - function for unknown specifiers
 * @c: spec
 * @buffer: buffer
 * @total_bytes: sum total bytes
 * @bytes: bytes
 * Return: int
 */
int handle_unknown(char c, char *buffer, int *total_bytes, int *bytes)
{
int error = 0;
if (*bytes + 2 > BUF_CAPACITY)
error = turnover(buffer, total_bytes, bytes);
if (error != -1)
{
if (c == '%')
{
buffer[(*bytes)++] = '%';
return (0);
}
else if (c < 33 || c > 126)
return (-1);
buffer[(*bytes)++] = '%';
buffer[(*bytes)++] = c;
return (0);
}
return (-1);
}
/**
 * none_specifiers - handle none specifiers
 * @c: char
 * @buffer: buffer
 * @tb: total_bytes
 * @b: bytes
 * Return: int
 */
int none_specifiers(char c, char *buffer, int *tb, int *b)
{
int error = 0;
if (c == '\n')
{
error = turnover(buffer, tb, b);
if (error == -1)
return (-1);
buffer[(*b)++] = c;
}
else
{
buffer[(*b)++] = c;
}
if (*b > BUF_CAPACITY)
error = turnover(buffer, tb, b);
if (error == -1)
return (-1);
return (0);
}
