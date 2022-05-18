#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_str - prints a string
 * @args: va_list
 * Return: string
 */
int print_str(va_list args)
{
int i = 0;
char *str;

str = va_arg(args, char *);

if (str == NULL)
str = "(null)";

for (; *str; str++)
{
putchar(*str), i++;
}
return (i);
}
/**
 * print_char - prints a character
 * @args: va_list
 * Return: character
 */
int print_char(va_list args)
{
int x;

x = 0;
x = va_arg(arguments, int);
_putchar(x);
return (1);
}
/**
 * print_int - print an integer or a digit
 * @args: va_list
 * Return: integer or digit
 */
int print_int(va_list args)
{
int i, d, len;
unsigned int x;

i  = va_arg(arguments, int);
d = 1;
len = 0;

if (i < 0)
{
len = len + _putchar('-');
x = i * -1;
}
else
{
x = i;
}

while (x / d > 9)
d = d * 10;

while (d != 0)
{
len = len + _putchar('0' + x / d);
x = x % d;
d = d / 10;
}

return (len);
}
