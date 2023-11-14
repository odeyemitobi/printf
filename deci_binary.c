#include "main.h"

/**
 * print_base - prints number in specified base (hex, HEX, binary, octal)
 * @xy: pointer
 * @params: struct
 * @base: base for conversion (16 for hex, HEX, 2 for binary, 8 for octal)
 * @uppercase: flag for uppercase hex (1 for uppercase, 0 for lowercase)
 * Return: bytes printed
 */

int print_base(va_list xy, params_t *params, int base, int uppercase)
{
	unsigned long l;
	char *str;
	int q = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(xy, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(xy, unsigned int);
	else
		l = (unsigned int)va_arg(xy, unsigned int);

	str = convert(l, base, CONVERT_UNSIGNED |
			(uppercase ? CONVERT_UPPERCASE : 0), params);

	if (params->hashtag_flag && l)
	{
		*--str = (base == 16) ? (uppercase ? 'X' : 'x') : '0';
		if (base == 16)
			*--str = '0';
	}

	params->unsign = 1;
	return (q += print_number(str, params));
}


/**
 * print_hex - hex
 * @xy: pointer
 * @params: struct
 * Return: printed
 */


int print_hex(va_list xy, params_t *params)
{
	return (print_base(xy, params, 16, 0));
}


/**
 * print_HEX - unsigned hex
 * @xy: pointer
 * @params: struct
 * Return: printed
 */


int print_HEX(va_list xy, params_t *params)
{
	return (print_base(xy, params, 16, 1));
}


/**
 * print_binary - number
 * @xy: pointer
 * @params: struct
 * Return: bytes printed
 */


int print_binary(va_list xy, params_t *params)
{
	return (print_base(xy, params, 2, 0));
}


/**
 * print_octal - octal numbers
 * @xy: pointer
 * @params: struct
 * Return: printed
 */


int print_octal(va_list xy, params_t *params)
{
	return (print_base(xy, params, 8, 0));
}
