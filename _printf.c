#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints anything given like the original printf
 * @format: last known argument
 * Return : number of characters to be  printed
 */
int _printf(const char *format, ...)
{
va_list args;
const char *ptr;
int num = 0;

if (format == NULL)
return (-1);

va_start(args, format);
for (ptr = format; *ptr; ptr++)
{
if (*ptr == '%' && *ptr + 1 == '%')
{
_putchar(*ptr), num++;
continue;
}
else if (*ptr == '%' && *ptr + 1 != '%')
{
switch (*++ptr)
{
case 's':
num += print_str(args);
break;
case 'c':
num += print_char(args);
break;
case '%':
_putchar('%'), num++;
break;
case '\0':
return (-1);
case 'i':
case 'd':
num += print_int(args);
break;
default:
_putchar('%'), _putchar(*ptr), num += 2;
}
}
else
_putchar(*ptr), num++;
}

va_end(args);
return (num);
}
