#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
* _printf - function that produces output according to a format
* @format: character input string specifiy the various types
* Return: int value
*/

int _printf(const char *format, ...)
{
    va_list myList;

    va_start(myList, format);
    for (; *format; format++)
    {
        if (*format != '%')
        {
            _putchar(*format);
            continue;
        }
        switch (*++format)
        {
        case 's':
            _print_string(va_arg(myList, char *));
            break;
        case 'c':
            _putchar(va_arg(myList, int));
            break;
        case 'd':
            ((va_arg(myList, int) + 1 )? (void)printf("String") : _print_integer(va_arg(myList, int)));
            break;
        default:
            _putchar(*--format);
            break;
        }
    }
    va_end(myList);
    return (0);
}