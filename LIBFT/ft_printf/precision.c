/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:11:50 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:11:52 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	in_precision(const char *format, t_attrs *stuff)
{
	while (format[stuff->i] && \
		format[stuff->i] >= '0' && format[stuff->i] <= '9')
	{
		stuff->precision = (stuff->precision * 10) + (format[stuff->i] - '0');
		stuff->i++;
	}
}

void			precision(va_list args, const char *format, t_attrs *stuff)
{
	if (format[stuff->i] == '.' && \
		(format[stuff->i + 1] >= '0' && format[stuff->i + 1] <= '9'))
	{
		stuff->precision = 0;
		stuff->i++;
		in_precision(format, stuff);
	}
	else if (format[stuff->i] == '.' && format[stuff->i + 1] == '*')
	{
		stuff->precision = 0;
		stuff->precision = va_arg(args, int);
		stuff->i = stuff->i + 2;
	}
	else if (format[stuff->i] == '.')
	{
		stuff->precision = 0;
		stuff->i++;
	}
}

void			precision_oct(t_attrs *stuff)
{
	if (stuff->precision > -1)
	{
		stuff->cnt = 0;
		octal_len(stuff->x, stuff);
		stuff->precision -= stuff->cnt;
		if (stuff->x >= 0 && stuff->flagplus != 0)
		{
			ft_putchar('+');
			stuff->flagplus = 0;
			stuff->res++;
			stuff->width--;
		}
		else if (stuff->x < 0 && stuff->flagplus == 0)
		{
			ft_putchar('-');
			stuff->res++;
			stuff->x = stuff->x * -1;
			stuff->precision++;
		}
		precision_oct_nxt(stuff);
	}
}

void			precision_dgt(t_attrs *stuff)
{
	if (stuff->precision > -1)
	{
		stuff->len = ft_nbrlen(stuff->x);
		stuff->precision -= stuff->len;
		if (stuff->x >= 0 && stuff->flagplus != 0)
		{
			ft_putchar('+');
			stuff->flagplus = 0;
			stuff->res++;
			stuff->width--;
		}
		else if (stuff->x < 0 && stuff->flagplus == 0)
		{
			ft_putchar('-');
			stuff->res++;
			stuff->x = stuff->x * -1;
			stuff->precision++;
		}
		precision_dgt_nxt(stuff);
	}
}

void			precision_dgt_ux(t_attrs *stuff, int len)
{
	if (stuff->precision > -1)
	{
		stuff->precision = stuff->precision - len;
		if (stuff->precision > 0)
			stuff->res += stuff->precision;
		while (stuff->precision > 0)
		{
			ft_putchar('0');
			stuff->precision--;
		}
	}
}
