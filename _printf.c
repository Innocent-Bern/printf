#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
* _printf - function that produces output according to a format
* @format: character input string specifiy the various types
* Return: int value
*/

int _printf(const char *format, ...)
{
    va_list myList;
    char *str_arg, c;
    int ival, count = 0;

    va_start(myList, format);
    for (; *format; format++)
    {
        if (*format != '%')
        {
			count += write(1, format, 1);
        } else 
        {
        switch (*++format)
        {
        case 's':
            str_arg = va_arg(myList, char *);
			count += write(1, str_arg, _str_len(str_arg));
        break;
        case 'c':
			c = (char)va_arg(myList, int);
			count += write(1, &c, 1);
        break;
        case 'd':
		ival = va_arg(myList, int);
		count += write(1, _print_integer(ival), _str_len(_print_integer(ival)));
        break;
        case 'i':
		ival = va_arg(myList, int);
		count += write(1, _print_integer(ival), _str_len(_print_integer(ival)));
        break;
        case '%':
        c = '%';
        count += write(1, &c, 1);
        break;
        default:
        count += write(1, --format, 1);
		    count += write(1, ++format, 1);
        break;
        }
        }
    }
    va_end(myList);
    return (count);
}
