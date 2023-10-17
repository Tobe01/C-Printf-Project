#include "main.h"
/**
 * print_uint - print unsigned int
 *@num: param
 *Return: count
 */
int print_uint(unsigned int num)
{
	int count = 0, i, digit, num_digits;
	unsigned int divisor, temp = num, temp_num;

	/* Count the number of digits in the number*/
	num_digits = 0;
	temp_num = temp;
	do {
		temp_num /= 10;
		num_digits++;
	} while (temp_num != 0);

	/* Handle the case when the number is 0*/
	if (num == 0)
	{
		count += _printf("0");
	}
	else
	{
		/* Print the digits of the number*/
		while (num_digits > 0)
		{
			divisor = 1;
			for (i = 1; i < num_digits; i++)
			{
				divisor *= 10;
			}
			digit = temp / divisor;
			count += _printf("%c", digit + '0');
			temp %= divisor;
			num_digits--;
		}
	}
	return (count);
}
