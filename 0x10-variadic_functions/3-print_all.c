#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_c - print a char
 * @c: char to print
 * Return: void
 */
void print_c(va_list c)
{
	printf("%c", va_arg(c, int));
}


/**
 * print_s - print a str
 * @s: str to print
 * Return: void
 */
void print_s(va_list s)
{
	char *str = va_arg(s, char *);
	if (str == NULL)
		str = "(nill)";
	printf("%s", str);
}



/**
 * print_i - print an int
 * @i: int to print
 * Return: void
 */
void print_i(va_list i)
{
	printf("%d", va_arg(i, int));
}



/**
 * print_f - print a float
 * @f: float to print
 * Return: void
 */
void print_f(va_list f)
{
	printf("%f", va_arg(f, double));
}



/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the func
 * Return: void
 */

void print_all(const char * const format, ...)
{
	unsigned int i = 0, j;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"f", print_f},
		{NULL, NULL}
	};
	va_list va;
	char *sep = "";

	va_start(va, format);

	while (format && format[i])
	{
		j = 0;
		while (p[j].t != NULL)
		{
			if (*(p[j].t) == format[i])
			{
				printf("%s", sep);
				p[j].f(va);
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	va_end(va);
	printf("\n");
}
