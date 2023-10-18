#ifndef PRINTF_
#define PRINTF_
#define BUF_CAPACITY 1024
#include <stdarg.h>
#include <unistd.h>
int print_pointer(void *ptr);
int print_char(char c);
int print_str(char *str);
int print_int(int num);
int print_uint(unsigned int num);
int print_hex(unsigned int num, int uppercase);


int _straff(const char *);
int _printf(const char *format, ...);
int turnover(char *, int *, int *);
int build_str(char *, char *, int *, int *);
int build_int(int, char *, int *, int *);
int build_bin(unsigned int, char *, int *, int *);
char *convert_int(long);
char *convert_unsigned_int(unsigned int);
char *convert(unsigned int, int);
char *convert_oct(unsigned int);
int zero_indicators(char, char *, int *, int *);
int zero_standard_indicators(va_list, char, char *, int *, int *);
int handle_unknown(char, char *, int *, int *);
int standard_indicators(va_list, char, char *, int *, int *);
int watch_data(va_list, char *, int, int);
int exit_error(va_list);
void reverse(char *);
int roT13(char *, char *, int *, int *);
char *_strcpy(char *, char *);
int handle_non_printable(char *, char *, int *, int *);
int dectohexa(int, char *, int *);
int unsigned_int(unsigned int, char *, int *, int *, char);
int convert_tohex(unsigned int, char, char *, int *, int *);
#endif 
