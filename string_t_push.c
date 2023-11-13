#include "main.h"

int print_from_to(char *start, char *stop, char *except)
{
	int add = 0;

	while (start <= stop
			&& (add += (start != except)
				? _putchar(*start) : 0, start++, 1))
		;
	return (add);
}


int print_rev(va_list xy, params_t *params)
{
	int add = 0;
	char *str = va_arg(xy, char *);
	(void)params;
	if (str)
		for (int len = 0; *str; str++, len++)
			add += _putchar(str[-1]);
	return (add);
}


int print_rot13(va_list xy, params_t *params)
{
	int c = 0, k = 0, r = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(xy, char *);
	(void)params;

	while (a[r] &&
			(c += (a[r] >= 'A' && a[r] <= 'Z') || (a[r] >= 'a' && a[r] <= 'z')
			 ? _putchar(arr[a[r] - 'A'])
			 : _putchar(a[r])),
			r++, 1)
		;
	return (c);
}
