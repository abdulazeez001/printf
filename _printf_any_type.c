#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * _printf_char - prints a character
 * @arg: character to be printed
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printf_char(va_list arg)
{
return (_putchar(va_arg(arg, int)));
}


/**
 * _printf_str - prints a string
 * @arg: string to be printed
 * Return: On success returns number of char printed.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _printf_str(va_list arg)
{
int i = 0;
char *str = va_arg(arg, char*);
if (str == NULL)
{
str = "(null)";
}
else if (*str == '\0')
{
return (-1);
}

while (*str)
{
_putchar(*str);
str++;
i++;
}

return (i);
}
