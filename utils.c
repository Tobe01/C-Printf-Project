#include "main.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * _strcpy -  copies the string
 * @dest : destination
 * @src: source
 * Return: pointer
 */
char *_strcpy(char *dest, char *src)
{
int len = 0, i = 0;
while (src[len] != '\0')
len++;
for (; i <= len; i++)
dest[i] = src[i];
return (dest);
}
/**
 * rot13 - encodes
 * @s: string
 * @buffer: buffer
 * @tb: total_bytes
 * @b: bytes
 * Return: int
 */
int roT13(char *s, char *buffer, int *tb, int *b)
{
int i, j, k, error = 0;
char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char rot_val[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
if (s == NULL)
s = "(null)";
if (_straff(s) > BUF_CAPACITY - *b)
error = overflow(buffer, tb, b);
if (error == -1)
return (-1);
for (i = 0; s[i]; i++)
{
k = 0;
for (j = 0; characters[j] && !k; j++)
if (s[i] == characters[j])
{
buffer[(*b)++] = rot_val[j];
k = 1;
}
if (!k)
buffer[(*b)++] = s[i];
}
return (0);
}
/**
 * overflow - buffer
 * @buffer: buffer
 * @tb: total_bytes
 * @b: bytes
 * Return: void
 */
int overflow(char *buffer, int *tb, int *b)
{
int error;
error = write(1, buffer, *b);
if (error == -1)
return (-1);
*tb = *tb + *b;
*b = 0;
return (0);
}
/**
 * _straff - string length.
 * @s: string
 * Return: int
 */
int _straff(const char *s)
{
int len;
if (*s == '\0')
return (0);
len = 1 + _straff(++s);
return (len);
}
/**
 * reverse - reverses.
 * @a: array
 * Return: void
 */
void reverse(char *a)
{
int i = 0, n = _straff(a);
for (; i < n / 2; i++)
{
char temp = a[i];
a[i] = a[n - i - 1];
a[n - i - 1] = temp;
}
}
