/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 16:52:37 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/06/06 16:52:39 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void			width_sc_place(t_attrs *stuff)
{
	int len;
	int res;

	len = ft_strlen(stuff->str);
	if (stuff->precision > 0 && ft_strlen(stuff->str) > 0 \
	&& stuff->precision < (int)ft_strlen(stuff->str))
	{
		res = len - stuff->precision;
		len -= res;
	}
	if (stuff->precision != 0)
		stuff->width = stuff->width - len;
	if (stuff->width > 0)
		stuff->res += stuff->width;
	while (stuff->width > 0)
	{
		ft_putchar(stuff->width_c);
		stuff->width--;
	}
}

void				width_sc(const char *format, t_attrs *stuff)
{
	if (stuff->flagzero != 0)
		stuff->width_c = '0';
	if (stuff->width != 0 && format[stuff->i] == 's')
		width_sc_place(stuff);
	else if (stuff->width != 0 && format[stuff->i] == 'c')
	{
		stuff->width = stuff->width - 1;
		if (stuff->width > 0)
			stuff->res += stuff->width;
		while (stuff->width > 0)
		{
			ft_putchar(stuff->width_c);
			stuff->width--;
		}
	}
}

void				width_dgt_place(t_attrs *stuff)
{
	if (stuff->flagplus != 0)
		stuff->width--;
	if (stuff->precision < stuff->len)
		stuff->width = stuff->width - stuff->len;
	else
	{
		if (stuff->x < 0)
			stuff->width--;
		stuff->width = stuff->width - stuff->precision;
	}
	if (stuff->width > 0)
		stuff->res += stuff->width;
	while (stuff->width > 0)
	{
		ft_putchar(stuff->width_c);
		stuff->width--;
	}
}
