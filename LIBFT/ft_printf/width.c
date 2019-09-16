/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:12:21 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:12:22 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	in_width(const char *format, t_attrs *stuff)
{
	while (format[stuff->i] && \
		format[stuff->i] >= '0' && format[stuff->i] <= '9')
	{
		stuff->width = (stuff->width * 10) + (format[stuff->i] - '0');
		stuff->i++;
	}
}

void			width(va_list args, const char *format, t_attrs *stuff)
{
	if (format[stuff->i] >= '0' && format[stuff->i] <= '9')
	{
		in_width(format, stuff);
	}
	else if (format[stuff->i] == '*')
	{
		stuff->width = va_arg(args, int);
		stuff->i++;
	}
}

void			width_dgt_aft(t_attrs *stuff, const char *format)
{
	if (stuff->flagzero != 0 && stuff->precision < 0 && stuff->flagminus == 0)
		stuff->width_c = '0';
	if (format[stuff->i] == 'o')
	{
		octal_len(stuff->x, stuff);
		stuff->len = stuff->cnt;
	}
	else if (stuff->precision != 0)
		stuff->len = ft_nbrlen(stuff->x);
	if (stuff->width != 0)
		width_dgt_place(stuff);
	if (stuff->flagplus != 0)
	{
		ft_putchar('+');
		stuff->res++;
		stuff->flagplus = 0;
	}
}

void			width_dgt(t_attrs *stuff, const char *format)
{
	if (stuff->flagzero != 0 && stuff->precision < 0 && stuff->flagminus == 0)
		stuff->width_c = '0';
	if (format[stuff->i] == 'o' && stuff->precision != 0)
	{
		octal_len(stuff->x, stuff);
		stuff->len = stuff->cnt;
	}
	else if (stuff->precision != 0)
		stuff->len = ft_nbrlen(stuff->x);
	if (stuff->width != 0)
		width_dgt_place(stuff);
	if (stuff->flagplus != 0)
	{
		ft_putchar('+');
		stuff->res++;
		stuff->flagplus = 0;
	}
}

void			width_dgt_ux(t_attrs *stuff, int len)
{
	if (stuff->flagzero != 0 && stuff->precision < 0)
		stuff->width_c = '0';
	if (stuff->width != 0)
	{
		if (stuff->width > stuff->precision && stuff->precision > 0 \
			&& stuff->width - stuff->precision > len && \
			(stuff->precision - len > 0))
			stuff->width = stuff->width - ((stuff->precision - len) + len);
		else if (stuff->width > stuff->precision)
			stuff->width -= len;
		else if (stuff->width <= stuff->precision && stuff->precision > 0)
			stuff->width = stuff->width - stuff->precision;
		if (stuff->width > 0)
			stuff->res += stuff->width;
		while (stuff->width > 0)
		{
			ft_putchar(stuff->width_c);
			stuff->width--;
		}
	}
}
