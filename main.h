#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
int _putchar(char c);
int _printf(const char *format, ...);
void _print_string(char *s);
void * _print_integer(int n);
int _isdigit(int c);
int _str_len(char *s);
char * _itoa (int i, char *strout, int base);
char * _strrev (char *str);
int _atoi(char *s);
void _str_copy(char *dest, char *src);
#endif