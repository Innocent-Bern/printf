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

void _print_integer(int n)
{
    char *s;
    int len = 0, num, i;
    num = n;

    while (n != 0)
    {
        len++;
        n /= 10;
    }
    s = malloc(sizeof(char) * len);
    for (i = 1; i <= len; i++)
    {
        *(s + len - i) = num % 10 + '0';
        num /= 10;
    }
    _print_string(s);
}
