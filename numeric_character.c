#include "main.h"

/**
 * _isdigit - digit
 * @c: the character
 *
 * Return: 1
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - string
 * @s: string
 *
 * Return: int
 */

int _strlen(char *s)
{
	int r = 0;

	while (*s++)
	{
		r++;
	}

	return (r);
}

/**
 * print_number - number
 * @str: string
 * @params: struct
 *
 * Return: chars
 */

int print_number(char *str, params_t *params)
{
	unsigned int len = _strlen(str);
	unsigned int precision =
		params->precision == UINT_MAX ? 0 : params->precision;
	char pad_char = params->zero_flag && !params->minus_flag ? '0' : ' ';

	if (!params->unsign && *str == '-')
	{
		str++;
		len--;
	}
	while (len++ < precision)
	{
		*--str = '0';
	}

	if (!params->minus_flag)
	{
		return (print_number_right_shift(str, params));
	}
	{
		return (print_number_left_shift(str, params));
	}
}

/**
 * print_number_right_shift - number
 * @str: string
 * @params: struct
 *
 * Return: chars printed
 */

int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0;
	char pad_char = params->zero_flag && !params->minus_flag ? '0' : ' ';

	if ((params->plus_flag || params->space_flag) &&
			!(*str == '-' || *str == '0'))
	{
		n += _putchar(params->plus_flag ? '+' : ' ');
	}

	while (_strlen(str) < params->width)
	{
		n += _putchar(pad_char);
	}

	n += _puts(str);

	return (n);
}

/**
 * print_number_left_shift - number
 * @str: string
 * @params:  struct
 *
 * Return: chars
 */

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0;
	char pad_char = params->zero_flag && !params->minus_flag ? '0' : ' ';

	if ((params->plus_flag || params->space_flag) &&
			!(*str == '-' || *str == '0'))
	{
		n += _putchar(params->plus_flag ? '+' : ' ');
	}

	n += _puts(str);

	while (_strlen(str) < params->width)
	{
		n += _putchar(pad_char);
	}

	return (n);
}
