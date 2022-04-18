#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	
	int len;
	int len2;

	len = _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	len2 = printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	
	_printf("String:[%s]\n", "I am a string !");
	_printf("String:[%s]\n", "I am a string !");
	_printf("String:[%s%%]\n", "I am a string !");
	printf("%d, %d\n",len,len2);

	
	return (0);
}
