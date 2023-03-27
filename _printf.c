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
    char *fmtpt;

    va_start(myList, format);
    for (fmtpt = format; *fmtpt; fmtpt++)
    {
        if (*fmtpt != '%')
        {
            _putchar(*fmtpt);
            continue;
        }
        if (*++fmtpt == 's')
        {
            _print_string(va_arg(myList, char *));
        } else if (*fmtpt == 'c')
        {
            _putchar(va_arg(myList, int));
        }
    }
    _putchar('\n');
    va_end(myList);
    return (0);
}