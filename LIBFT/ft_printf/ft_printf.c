/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:08:14 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:08:16 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		initialize(t_attrs *stuff)
{
	stuff->flagminus = 0;
	stuff->flagplus = 0;
	stuff->flaghash = 0;
	stuff->flagzero = 0;
	stuff->flagspace = 0;
	stuff->width = 0;
	stuff->precision = -1;
	stuff->length = ft_strnew(3);
	stuff->x = 0;
	stuff->f = 0;
	stuff->u_x = 0;
	stuff->width_c = ' ';
	stuff->cnt = 0;
	stuff->len = 0;
	stuff->oct_len = 0;
}

static	void	handler(t_attrs *stuff, const char *format, va_list args)
{
	initialize(stuff);
	flags(stuff, format);
	width(args, format, stuff);
	precision(args, format, stuff);
	length(format, stuff);
	specifier(args, format, stuff);
}

static void		iterate(const char *format, t_attrs *stuff, va_list args)
{
	while (format[stuff->i])
	{
		if (format[stuff->i] == '%' && format[stuff->i + 1] == '%')
		{
			stuff->res++;
			ft_putchar('%');
			stuff->i++;
		}
		else if (format[stuff->i] == '%')
		{
			stuff->i++;
			handler(stuff, format, args);
		}
		else
		{
			ft_putchar(format[stuff->i]);
			stuff->res++;
		}
		if (!format[stuff->i])
			break ;
		stuff->i++;
	}
}

int				ft_printf(const char *format, ...)
{
	va_list args;
	t_attrs stuff;

	stuff.res = 0;
	stuff.i = 0;
	va_start(args, format);
	iterate(format, &stuff, args);
	va_end(args);
	return (stuff.res);
}
