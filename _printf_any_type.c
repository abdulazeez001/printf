#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

int _printf_int(va_list arg)
{

unsigned int div = 1, i, resp, numOfcharP = 0;
int n = va_arg(arg, int);

if (n < 0)
{
	_putchar('-');
	numOfcharP++;
	n *= -1;
}

for (i = 0; n / div > 9; i++, div *= 10)
;

for (; div >= 1; n %= div, div /= 10, numOfcharP++)
{
	resp = n / div;
	_putchar('0' + resp);
}
return (numOfcharP);
}



/**
 * print_STR - prints a string with a `S` (upper case) specificer
 * @arg: argument
 * Return: number of character printed
 */

int _printf_STR(va_list arg)
{
int i;
char *str = va_arg(arg, char*);

if (str == NULL)
	str = "(null)";
else if (*str == '\0')
	return (-1);

for (i = 0; str[i]; i++)
{
	if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
	{
		_putchar('\\');
		_putchar('x');
		if (i < 16)
			_putchar('0');

		_printf_unsignedIntToHex(str[i], 'A');
	}
	else
		_putchar(str[i]);
}

return (i);
}


/**
 * print_unsigned - prints an unsigned int.
 * @arg: argument
 * Return: 0
 */

int _printf_unsigned(va_list arg)
{
int div = 1, i, resp;
unsigned int n = va_arg(arg, unsigned int);

for (i = 0; n / div > 9; i++, div *= 10)
;

for (; div >= 1; n %= div, div /= 10)
{
	resp = n / div;
	_putchar('0' + resp);
}
return (i + 1);
}

/**
 * print_hex - prints a hexadecimal in lower case
 * @arg: list that contains hexadecimal to print
 * Return: number of digits printed
 */

int _printf_hex(va_list arg)
{
	return (print_hex_base(arg, 'a'));
}

/**
 * print_HEX - prints a hexadecimal in upper case
 * @arg: list that contains hexadecimal to print
 * Return: number of digits printed
 */

int _printf_HEX(va_list arg)
{
	return (print_hex_base(arg, 'A'));
}


/**
 * print_unsignedToBinary - prints an integer.
 * @arg: argument
 * Return: 0
 */
int _printf_unsignedToBinary(va_list arg)
{

unsigned int n = va_arg(arg, unsigned int);
unsigned int printed;

print_binary(n, &printed);
print_binary(n, &printed);

return (printed);
}


/**
 * print_oct - prints number in octal base.
 * @arg: list containing octal number to be printed
 * Return: number of octals printed
 */

int _printf_oct(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int copy;
	char *octa;
	int i, j, charPrinted = 0;

	if (num == 0)
		return (_putchar('0'));
	for (copy = num; copy != 0; j++)
	{
		copy = copy / 8;
	}
	octa = malloc(j);
	if (!octa)
		return (-1);

	for (i = j - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}

	for (i = 0; i < j && octa[i] == '0'; i++)
		;
	for (; i < j; i++)
	{
		_putchar(octa[i]);
		charPrinted++;
	}
	free(octa);
	return (charPrinted);
}

/**
 * print_unsignedIntToHex - prints unsigned int to hexadecimal.
 * @num: number to print
 * @_case: letter `a` on the case to print it (upper or lower)
 * Return: number or char printed
 */
int _printf_unsignedIntToHex(unsigned int num, char _case)
{
	unsigned int num2;
	int i, j, remainder, nbrCharacters = 0;
	char *numhex;

	for (num2 = num; num2 != 0; nbrCharacters++, num2 /= 16)
	;

	numhex = malloc(nbrCharacters);
	for (i = 0; num != 0; i++)
	{
		remainder = num % 16;
		if (remainder < 10)
			numhex[i] = remainder + '0';
		else
			numhex[i] = remainder - 10 + _case;
		num = num / 16;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(numhex[j]);
	free(numhex);
	return (nbrCharacters);
}