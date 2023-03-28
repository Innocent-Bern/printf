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

char * _strrev (char *str)
{
    int i;
    int len;
    char c;

    if (!str)
    {
        return (NULL);
    }

    len = _str_len(str);

    for (i = 0; i < len / 2; i++)
    {
        c = str[i];
        str[i] = str[len - i - 1];
        str[len - i -1] = c;
    }
    return (str);
}

char * _itoa (int i, char *strout, int base)
{
    char *str = strout;
    int digit, sign = 0;

    if (i < 0)
    {
        sign = 1;
        i *= -1;
    }

    while (i)
    {
        digit = i % base;
        *str = (digit > 9) ? ('A' + digit -10) : '0' + digit;
        i = i / base;
        str++;
    }
    if (sign)
    {
        *str++ = '-';
    }
    *str = '\0';
    _strrev(strout);
    return (strout);
}

int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	do {

		if (*s == '-')
			sign *= -1;

		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');

		else if (num > 0)
			break;
	} while (*s++);

	return (num * sign);
}

void _str_copy(char *dest, char *src)
{
    while ((*dest++ = *src++))
        ;
}
