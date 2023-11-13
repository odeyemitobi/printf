#include "main.h"

void init_params(params_t *params, va_list xy)
{
	params->flags = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)xy;
}
