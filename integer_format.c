#include "main.h"

/**
 * get_precision - precision string
 * @s: string
 * @params: the parameters struct
 * @xy: pointer
 * Return: new pointer
*/

char *get_precision(char *s, params_t *params, va_list xy)
{
	if (*s != '.')
		return (s);
	s++;
	params->precision = (*s == '*') ? va_arg(xy, int) : _strtol(s, &s, 10);
	return (s);
}

