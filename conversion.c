#include "main.h"
#include <stdlib.h>
/**
 * convert_int - convert int to string
 * @num: number
 * Return: char pointer (string)
 */
char *convert_int(long num)
{
int isNegative = 0, length, i;
char *str;
int temp;
if (num < 0)
{
isNegative = 1;
num = -num;
}
length = isNegative ? 2 : 1;
temp = num;
while (temp /= 10)
length++;
str = (char *)malloc(length + 1);
if (str == NULL)
return (NULL);
i = length - 1;
str[i + 1] = '\0';
do {
str[i--] = num % 10 + '0';
num /= 10;
} while (num > 0);
if (isNegative)
str[0] = '-';
return (str);
}
/**
 * convert_unsigned_int - convert int to string
 * @num: convert number
 * Return: char pointer (string)
 */
char *convert_unsigned_int(unsigned int num)
{
int length, i;
char *str;
unsigned long int temp;
length = 1;
temp = num;
while (temp /= 10)
length++;
str = (char *)malloc(length + 1);
if (str == NULL)
return (NULL);
i = length - 1;
str[i + 1] = '\0';
do {
str[i--] = num % 10 + '0';
num /= 10;
} while (num > 0);
return (str);
}
/**
 * convert - int to binary
 * @num: int
 * @type: base
 * Return: char *
 */
char *convert(unsigned int num, int type)
{
int i = 0, j = 0;
char *c = (char *)malloc(sizeof(char) * 32), *n;
if (c == NULL)
return (NULL);
if (num == 0)
{
i = 1;
c[0] = '0';
}
else
{
while (num != 0)
{
c[i] = '0' + num % type;
i++;
num /= type;
}
}
n = (char *)malloc(sizeof(char) * (i + 1));
if (n == NULL)
return (NULL);
while (j != i)
{
n[j] = c[j];
j++;
}
n[j] = '\0';
free(c);
reverse(n);
return (n);
}
/**
 * dectohexa - dev to hex
 * @n: int
 * @buffer: buffer
 * @b: bytes
 * Return: char *
 */
int dectohexa(int n, char *buffer, int *b)
{
char hexBuffer[9], ch, *res, temp;
int index = 0, i, j, rem = 0;
while (n != 0)
{
rem = n % 16;
if (rem < 10)
ch = rem + '0';
else
ch = rem + 'A' - 10;
hexBuffer[index++] = ch;
n = n / 16;
}
hexBuffer[index] = '\0';
i = 0;
j = index - 1;
while (i <= j)
{
temp = hexBuffer[i];
hexBuffer[i] = hexBuffer[j];
hexBuffer[j] = temp;
i++;
j--;
}
res = (char *)malloc(_straff(hexBuffer) + 1);
if (res != NULL)
{
_strcpy(res, hexBuffer);
buffer[(*b)++] = 92;
buffer[(*b)++] = 'x';
if (_straff(res) < 2)
buffer[(*b)++] = '0';
buffer[(*b)++] = res[0];
if (_straff(res) > 1)
buffer[(*b)++] = res[1];
free(res);
return (0);
}
return (-1);
}
/**
 * convert_tohex - converts to hex
 * @n: numbers
 * @c: type
 * @buffer: buffer
 * @b: bytes
 * @tb: total bytes
 * Return: int
 */
int convert_tohex(unsigned int n, char c, char *buffer, int *b, int *tb)
{
char hexBuffer[9], ch, temp;
int index = 0, i, j, rem = 0, error = 0;
while (n != 0)
{
rem = n % 16;
if (rem < 10)
ch = rem + '0';
else
{
if (c == 'x')
ch = rem + 'a' - 10;
else
ch = rem + 'A' - 10;
}
hexBuffer[index++] = ch;
n = n / 16;
}
hexBuffer[index] = '\0';
i = 0;
j = index - 1;
while (i <= j)
{
temp = hexBuffer[i];
hexBuffer[i++] = hexBuffer[j];
hexBuffer[j--] = temp;
}
if (_straff(hexBuffer) > (BUF_CAPACITY - *b))
error = overflow(buffer, tb, b);
if (error != -1)
{
i = 0;
while (hexBuffer[i] != '\0')
{
buffer[(*b)++] = hexBuffer[i];
i++;
}
return (0);
}
return (-1);
}
