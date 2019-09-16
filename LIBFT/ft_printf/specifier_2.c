/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   specifier_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 16:21:39 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/06/06 16:21:41 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	place_oct_u(const char *format, t_attrs *stuff)
{
	if (format[stuff->i] == 'u' && stuff->precision != 0)
	{
		precision_dgt(stuff);
		stuff->res += ft_nbrlen(stuff->x);
		ft_putnbr(stuff->x);
	}
	else if (format[stuff->i] == 'o')
	{
		if (stuff->flaghash == 1 && ((stuff->precision <= 0 \
			&& stuff->x != 0) || (stuff->precision == 0 \
			&& stuff->x == 0)))
		{
			ft_putchar('0');
			stuff->res++;
		}
		if (stuff->precision != 0 || stuff->x != 0)
		{
			precision_oct(stuff);
			octal(stuff->x, stuff);
			stuff->res += stuff->oct_len;
			stuff->oct_len = 0;
		}
	}
}

void	put_dgt(t_attrs *stuff, const char *format)
{
	stuff->res += ft_nbrlen(stuff->x);
	ft_putnbr(stuff->x);
	if (stuff->flagminus != 0)
		width_dgt(stuff, format);
}
