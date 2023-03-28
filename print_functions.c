#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

void _print_string(char *s)
{
    while(*s)
    {
        _putchar(*s++);
    }
}

void * _print_integer(int n)
{
    char *s;
    int len = 0, num, i;
    num = n;
    while (n != 0)
    {
        len++;
        n /= 10;
    }

    s = malloc(sizeof(char) * len + 1);

    for (i = 1; i <= len; i++)
    {
        *(s + len - i) = num % 10 + '0';
        num /= 10;
    }
    return(s);
}

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
        return (1);
    }
	else
		return (0);
}

int _str_len(char *s)
{
    int len = 0;

    while (*s)
    {
        len++;
        s++;
    }
    return (len);
}

void _str_copy(char *dest, char *src)
{
    while ((*dest++ = *src++))
        ;
}
