#include "main.h"


int print_number_base(va_list xy, params_t *params, int base)
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

	str = convert(l, base, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
	{
		*--str = base == 16 ? 'x' : '0';
		*--str = '0';
	}

	params->unsign = 1;
	return (q += print_number(str, params));
}

int print_hex(va_list xy, params_t *params)
{
	return (print_number_base(xy, params, 16));
}

int print_HEX(va_list xy, params_t *params)
{
	return (print_number_base(xy, params, 16));
}

int print_binary(va_list xy, params_t *params)
{
	return (print_number_base(xy, params, 2));
}

int print_octal(va_list xy, params_t *params)
{
	return (print_number_base(xy, params, 8));
}
