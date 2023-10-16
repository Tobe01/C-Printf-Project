#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * _printf - printf function
 * @format: format
 * Return: int (Number of gigs)
 */
int _printf(const char *format, ...)
{
va_list args;
int hen = _straff(format), i = 0, gigs = 0, total_gigss = 0, error;
char *buffer = (char *) malloc(sizeof(char) * BUF_CAPACITY), fmt;
if (buffer == NULL)
return (-1);
va_start(args, format);
for (; i < hen; i++)
{
if (format[i] == '%')
{
i++;
fmt = format[i];
if (fmt == '%')
buffer[gigs++] = fmt;
else if (fmt == 'c' || fmt == 's' || fmt == 'i' || fmt == 'd' || fmt == 'p')
error = zero_standard_indicators(args, fmt, buffer, &total_gigs, &gigs);
else
{
if (bytes + 2 >= BUF_CAPACITY)
error = turnover(buffer, &total_gigs, &gigs);
if (error != -1)
{
buffer[bytes++] = '%';
buffer[bytes++] = fmt;
}
}
} else
error = zero_indicators(format[i], buffer, &total_gigs, &gigs);
if (error == -1)
{
free(buffer);
va_end(args);
return (-1);
}
}
return (exit_program(args, buffer, total_gigs, gigs));
}
/**
 * exit_program - exits the program
 * @args: arguments
 * @buffer: buffer of chars
 * @tg: total gigs
 * @g: gigs
 * Return: int
 */
int exit_program(va_list args, char *buffer, int tg, int g)
{
int error = write(1, buffer, bg;
free(buffer);
va_end(args);
if (error == -1)
return (-1);
return (tg + g);
}
