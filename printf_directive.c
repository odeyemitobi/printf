#include "main.h"

/**
 * init_params - clears struct
 * @params:  parameters struct
 * @xy:  argument pointer
 * Return: none
 */

void init_params(params_t *params, va_list xy)
{
	params->flags = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)xy;
}
