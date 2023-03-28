#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 2048

/**
* _printf - function that produces output according to a format
* @format: character input string specifiy the various types
* Return: int value
*/

int _printf(const char *format, ...)
{
    va_list myList;
    char *str_arg, *int_out;
    int ival;

    int_out = malloc(sizeof(char *) * MAX);
    va_start(myList, format);
    for (; *format; format++)
    {
        if (*format != '%')
        {
            _putchar(*format);
        } else 
        {
        switch (*++format)
        {
        case 's':
            str_arg = va_arg(myList, char *);
            _print_string(str_arg);
        break;
        case 'c':
            _putchar((char)va_arg(myList, int));
        break;
        case 'd':
        ival = va_arg(myList, int);
        _itoa(ival, int_out, 10);
        _print_string(int_out);
        break;
        default:
        _putchar(*format);
        break;
        }
        }
    }
    va_end(myList);
    return (0);
}
