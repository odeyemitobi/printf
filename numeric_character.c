#include "main.h"

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int _strlen(char *s)
{
	int r = 0;

	while (*s++)
	{
		r++;
	}

	return (r);
}

int print_number(char *str, params_t *params)
{
	unsigned int len = _strlen(str);
	unsigned int precision =
		params->precision == UINT_MAX ? 0 : params->precision;
	char pad_char = params->zero_flag && !params->minus_flag ? '0' : ' ';

	unsigned int n = 0;
	if (params->minus_flag)
	{
		if (!params->unsign && *str == '-')
		{
			n += _putchar('-');
			str++;
			len--;
		}
		if (params->plus_flag && !(*str == '-' || *str == '0'))
		{
			n += _putchar('+');
		}
		n += _puts(str);

		while (len++ < precision) n += _putchar('0');

		while (len++ < params->width) n += _putchar(pad_char);

	} else
	{
		while (len++ < precision) n += _putchar('0');

		if (!params->unsign && *str == '-')

		{
			n += _putchar('-');
			str++;
			len--;
		}
		if (params->plus_flag && !(*str == '-' || *str == '0'))
		{
			n += _putchar('+');
		}
		n += _puts(str);
		while (len++ < params->width) n += _putchar(pad_char);
	}
	return (n);
}
