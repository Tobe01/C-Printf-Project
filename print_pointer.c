#include "main.h"
/**
 *print_pointer - convert address to hexadecimal
 *@ptr: take pointer as param
 *Return: count
 */
int print_pointer(void *ptr)
{
	unsigned long num = (unsigned long)ptr;
	int i, index, remainder, count = 0;
	char  hex_string[20],  hex_digits[] = "0123456789abcdef";

	/* Print '0x' prefix for pointers*/
	count += _printf("0x");
	/*Handle the case when the pointer is NULL*/
	if (num == 0)
	{
		count += _printf("0");
	} else
	{
		/* Assuming a maximum of 20 characters for the hexadecimal representation*/
		index = 0;

		 /* Convert the pointer to hexadecimal */
		while (num != 0)
		{
			remainder = num % 16;
			hex_string[index++] = hex_digits[remainder];
			num /= 16;
		}

		/* Print the hexadecimal number in reverse order */
		for  (i = index - 1; i >= 0; i--)
		{
			count += _printf("%c", hex_string[i]);
		}
	}

	return (count);
}
