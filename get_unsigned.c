#include "main.h"

char *convert(long int num, int base, int flags)
{
	static char arrange[16] = "0123456789abcdef";
	static char buffer[50];
	char *pointer = &buffer[49];
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
		n = -num;

	*pointer = '\0';
	do {
		*--pointer = arrange[n % base];
		n /= base;
	} while (n != 0);
	return (pointer);
}



int print_unsigned(va_list xy, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = va_arg(xy, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(xy, unsigned int);
	else
		l = (unsigned int)va_arg(xy, unsigned int);

	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED), params));
}


int print_address(va_list xy, params_t *params)
{
	unsigned long int n = va_arg(xy, unsigned long int);
	char *new_str;

	if (!n)
		return (_puts("(nil)"));

	new_str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE);
	*--new_str = 'x';
	*--new_str = '0';

	return (print_number(new_str, params));
}
