#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 2018
/**
* _printf - function that produces output according to a format
* @format: character input string specifiy the various types
* Return: int value
*/

int _printf(const char *format, ...)
{
    va_list myList;
    char *buff, tmp[20];
    int j = 0, i = 0, ival;
    char *str_arg;

    buff = malloc(sizeof(char *) * MAX);

    va_start(myList, format);
    for (i = 0; *(format + i); i++)
    {
        if (*(format + i) != '%')
        {
            buff[j] = *(format + i);
            j++;
        } else 
        {
            i++;
        switch (*(format + i))
        {
        case 's':
        str_arg = va_arg(myList, char *);
        _str_copy(&buff[j], str_arg);
        j += _str_len(str_arg);
        break;
        case 'c':
        buff[j] = (char)va_arg(myList, int);
        j++;
        break;
        case 'd':
        ival = va_arg(myList, int);
        _itoa(ival, tmp, 10);
        _str_copy(&buff[j], tmp);
        j += _str_len(tmp);
        break;
        default:
            buff[j] = *(format + i);
            j++;
            break;
        }
        }
    }
    fwrite(buff, j, 1, stdout);
    va_end(myList);
    free(buff);
    return (0);
}
