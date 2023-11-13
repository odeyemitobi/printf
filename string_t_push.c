STRING_T_PUSH.C

#include "main.h"



int print_from_to(char *start, char *stop, char *except)
{
	int add = 0;

	while (start <= stop)
	{
		if (start != except)
			add += _putchar(*start);
		start++;
	}
	return (add);
}



int print_rev(va_list xy, params_t *params) {
	char *str = va_arg(xy, char *);
	(void)params;

	print_custom(str, [](char c) -> int { return _putchar(c); });

	return (0);
}

int print_rot13(va_list xy, params_t *params) {
	char *str = va_arg(xy, char *);
	(void)params;

	print_custom(str, [](char c) -> int {
			int k = c - 65;
			char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM   nopqrstuvwxyzabcdefghijklm";

			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			return _putchar(arr[k]);
			else
			return _putchar(c);
			});

	return (0);
}




