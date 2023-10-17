#include "main.h"
/**
 *print_hex - print hexadecimal
 *@num: as param
 *@uppercase: as param
 *Return: count
 */
int print_hex(unsigned int num, int uppercase)
{
	int count = 0, i, remainder, index;
	char hex_digits[] = "0123456789abcdef";
	char hex_string[20];

	if (uppercase)
	{
		hex_digits[10] = 'A';
		hex_digits[11] = 'B';
		hex_digits[12] = 'C';
		hex_digits[13] = 'D';
		hex_digits[14] = 'E';
		hex_digits[15] = 'F';
	}

	/* Handle the case when the number is 0*/
	if (num == 0)
	{
		count += _printf("0");
	}
	else
	{
		/* Assuming a maximum of 20 characters for*/
		/*the hexadecimal representation*/
		index = 0;

		/* Convert the number to hexadecimal*/
		while (num != 0)
		{
			remainder = num % 16;
			hex_string[index++] = hex_digits[remainder];
			num /= 16;
		}

		/* Print the hexadecimal number in reverse order*/
		for (i = index - 1; i >= 0; i--)
		{
			count += _printf("%c", hex_string[i]);
		}
	}
	return (count);
}
