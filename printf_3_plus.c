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
			switch (*++format)
			{
				case 'c':
					count += putchar(va_arg(args, int));
					break;
				case 's':
					count += fputs(va_arg(args, const char*), stdout);
					break;
				case '%':
					count += putchar('%');
					break;
				default:
					/* Ignore unsupported conversion specifiers. */
					break;
			}
		} else
		{
			count += putchar(*format);
		}
		format++;
	}
va_end(args);
return (count);
}
