/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   specifier_f.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:12:10 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:12:11 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				specifier_f(t_attrs *stuff, va_list args, const char *format)
{
	if (format[stuff->i] == 'f' && ft_strcmp(stuff->length, "L") == 0)
	{
		handle_lfloat(stuff, args);
		return (1);
	}
	else if (format[stuff->i] == 'f' && ft_strcmp(stuff->length, "l") == 0)
	{
		handle_float(stuff, args);
		return (1);
	}
	return (0);
}

void			put_plus(t_attrs *stuff)
{
	ft_putchar('+');
	stuff->res++;
}

void			width_f(t_attrs *stuff)
{
	int	precision;

	precision = stuff->precision;
	if (precision <= -1)
		precision = 7;
	if (stuff->flagzero != 0)
		stuff->width_c = '0';
	if (stuff->width != 0)
	{
		stuff->len = ft_nbrlen((long int)stuff->f);
		stuff->width = stuff->width - (stuff->len + precision);
		if ((stuff->flagplus == 1 && stuff->f > 0))
			stuff->width--;
		if (stuff->width > 0)
			stuff->res = stuff->res + stuff->width;
		while (stuff->width > 0)
		{
			ft_putchar(stuff->width_c);
			stuff->width--;
		}
	}
	if (stuff->flagplus != 0 && stuff->f > 0 && stuff->flagzero != 0)
		put_plus(stuff);
}
