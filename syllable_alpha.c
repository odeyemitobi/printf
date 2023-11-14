#include "main.h"

/**
 * print_char - prints character
 * @xy:  pointer
 * @params: parameters struct
 *
 * Return: number of characters printed
 */

int print_char(va_list xy, params_t *params)
{
	char space_char = ' ';
	int pad = params->width - 1, add = 0;
	char ch = va_arg(xy, int);

	if (!params->minus_flag)
	{
		while (pad--)
			add += _putchar(space_char);
	}
	add += _putchar(ch);
	while (pad--)
		add += _putchar(space_char);
	return (add);
}


/**
 * print_int - prints integer
 * @xy: pointer
 * @params: parameters struct
 *
 * Return: numberof characters printed
 */


int print_int(va_list xy, params_t *params)
{
	long l = va_arg(xy, int);
	
	return (print_number(convert(l, 10, 0, params), params));
}


/**
 * print_string - prints string
 * @xy:  pointer
 * @params: parameters struct
 *
 * Return: number of characters printed
 */


int print_string(va_list xy, params_t *params)
{
	char *str = va_arg(xy, char *);
	int pad = params->width - _strlen(str), add = 0;

	if (!params->minus_flag)
	{
		while (pad--)
			add += _putchar(' ');
	}
	add += _puts(str);
	while (pad--)
		add += _putchar(' ');
	return (add);
}


/**
 * print_percent - prints
 * @xy: pointer
 * @params: struct
 *
 * Return: number of characters printed
 */

int print_percent(va_list xy, params_t *params)
{
	(void)xy;
	(void)params;
	return (_putchar('%'));
}


/**
 * print_S - format specifier
 * @xy: pointer
 * @params: parameters
 *
 * Return: number of characters printed
 */

int print_S(va_list xy, params_t *params)
{
	char *str = va_arg(xy, char *), *hex;
	int add = 0;

	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			add += _putchar('\\');
			add += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				add += _putchar('0');
			add += _puts(hex);
		} else
		{
			add += _putchar(*str);
		}
	}
	return (add);
}

