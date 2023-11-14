#include "main.h"

/**
 * _printf - prints to the standard output
 * @format: format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	int add = 0;
	va_list xy;
	char *p;

	va_start(xy, format);

	if (!format || (*format == '%' && !format[1]))
		return (-1);

	for (p = (char *)format; *p; p++)
	{
		if (*p != '%')
		{
			add += _putchar(*p);
			continue;
		}

		p = get_and_process_format_spec(p, xy, &add);
	}

	_putchar(BUF_FLUSH);
	va_end(xy);
	return (add);
}

