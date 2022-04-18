#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 * Desc: Header file containing prototypes for all functions
 *       used for my printf project .
 */

#include <stdarg.h>

int _putchar(char c);
int _printf_char(va_list arg);
int _printf_str(va_list arg);
int _printf(const char *format, ...);
/**
 * struct print_type - structure definition for print type
 * @fmt: format to print
 * @_print_type: function to print format type
 */

typedef struct print_type
{
    char *fmt;
    int (*_print_type)(va_list);
} print_type;

#endif
