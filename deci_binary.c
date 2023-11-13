#include "main.h"

/**
 * print_hex - hex
 * @xy: pointer
 * @params: struct
 * Return: printed
 */

int print_hex(va_list xy, params_t *params)
{
	return (print_number_base(xy, params, 16));
}

/**
 * print_HEX - unsigned hex
 * @xy: pointer
 * @params: struct
 * Return: printed
 */

int print_HEX(va_list xy, params_t *params)
{
	return (print_number_base(xy, params, 16));
}

/**
 * print_binary - number
 * @xy: pointer
 * @params: struct
 * Return: bytes printed
 */

int print_binary(va_list xy, params_t *params)
{
	return (print_number_base(xy, params, 2));
}

/**
 * print_octal - octal numbers
 * @xy: pointer
 * @params: struct
 *
 * Return: printed
 */

int print_octal(va_list xy, params_t *params)
{
	return (print_number_base(xy, params, 8));
}
