#include "main.h"
#include <stdarg.h>

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
        if (*++format == 's')
        {
            _print_string(va_arg(myList, char *));
        } else if (*format == 'c')
        {
            _putchar(va_arg(myList, int));
        } else 
        {
            _putchar(*--format);
        }
    }
    va_end(myList);
    return (0);
}