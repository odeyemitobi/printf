#include "main.h"

int print_char(va_list xy, params_t *params)
{
	int ch = va_arg(xy, int);
	int pad = params->width - 1;
	int add = (params->minus_flag) ? _putchar(ch) + pad : pad + _putchar(ch)
		;
	
	while (pad-- > 0) add += _putchar(' ')
		;
	
	return (add);
}

int print_int(va_list xy, params_t *params)
{
	long l = (params->l_modifier) ? va_arg(xy, long) :
		 (params->h_modifier) ? (short int)va_arg(xy, int) : va_arg(xy, int);
	return (print_number(convert(l, 10, 0, params), params));
}

int print_string(va_list xy, params_t *params)
{
	char *str = va_arg(xy, char *);
	if (!str) str = NULL_STRING;
	unsigned int pad = params->width - _strnlen(str, params->precision);
	int add = (params->minus_flag) ? _puts(str, params->precision) + pad : pad + _puts(str, params->precision);
	return (add);
}

int print_percent(va_list xy, params_t *params)
{
	(void)xy;
	(void)params;
	return (_putchar('%'));
}

int print_S(va_list xy, params_t *params)
{
	char *str = va_arg(xy, char *);
	if (!str) return _puts(NULL_STRING);
	int add = 0;
	for (; *str; str++)
		add += (*str > 0 && *str < 32) || *str >= 127 ? _putchar('\\') + _putchar('x') + ((_puts(convert(*str, 16, 0, params) + 1)) ? 1 : _putchar('0')) + _puts(convert(*str, 16, 0, params)) : _putchar(*str);
	return (add);
}





