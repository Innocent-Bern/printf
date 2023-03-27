#include "main.h"
#include <stdarg.h>

/**
* _printf - function that produces output according to a format
* @format: character input string specifiy the various types
* Return: int value
*/

void _print_string(char *s)
{
    while(*s)
    {
        _putchar(*s++);
    }
}

int _printf(const char *format, ...)
{
    va_list myList;
    char *fmtpt, *myListString;

    va_start(myList, format);

    for (fmtpt = format; *fmtpt; fmtpt++)
    {
        if (*fmtpt != '%')
        {
            _putchar(*fmtpt);
            continue;
        }
    }
    _putchar('\n');
    va_end(myList);
    return (0);
}