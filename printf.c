#include <stdarg.h>
#include "main.h"
/**
 *_printf - print any given param
 *@format: param
 *Return: count
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);


	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += print_char(va_arg(args, int));
			else if (*format == 's')
				count += print_str(va_arg(args, char*));
			else if (*format == 'd' || *format == 'i')
				count += print_int(va_arg(args, int));
			else if (*format == 'u')
				count += print_uint(va_arg(args, unsigned int));
			else if (*format == 'x')
				count += print_hex(va_arg(args, unsigned int), 0);
			else if (*format == 'X')
				count += print_hex(va_arg(args, unsigned int), 1);
			else if (*format == 'p')
				count += print_pointer(va_arg(args, void*));
			else if (*format == '%')
				count += print_char('%');
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
