#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints to the standard output
 * @format: format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			/* Handle special format specifiers */
			count += print_special_format(format, args);
			format += 2;
		} else
		{
			/* Print the character */
			count += putchar(*format);
			format++;
		}
	}
va_end(args);
return (count);
}
