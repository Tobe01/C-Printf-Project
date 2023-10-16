#ifndef PRINTF_
#define PRINTF_
#define BUF_CAPACITY 1024
#include <stdarg.h>
int _straff(const char *);
int _printf(const char *format, ...);
int turnover(char *, int *, int *);
int build_str(char *, char *, int *, int *);
int build_int(int, char *, int *, int *);
char *transform_int(int);
int zero_indicators(char, char *, int *, int *);
int zero_standard_indicators(va_list, char, char *, int *, int *);
int watch_data(va_list, char *, int, int);
#endif 
