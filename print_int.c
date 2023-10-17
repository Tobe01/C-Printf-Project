#include "main.h"
/**
 * print_int - print number
 *@num: param
 *Return: count
 */
int print_int(int num)
{
	int count = 0, num_digits = 0, temp_num, divisor = 1;
	int i, temp = num, digit;

	/* Handle negative numbers */
	if (temp < 0)
	{
		count += _printf("-");
		temp = -temp;
	}
	/* Count the number of digits in the number */
	temp_num = temp;
	do {
		temp_num /= 10;
		num_digits++;
	} while (temp_num != 0);
	/* Print the digits of the number */
	while (num_digits > 0)
	{
		for (i = 1; i < num_digits; i++)
		{
			divisor *= 10;
		}
		digit = temp / divisor;
		count += _printf("%c", digit + '0');
		temp %= divisor;
		num_digits--;
	}

	return (count);
}
