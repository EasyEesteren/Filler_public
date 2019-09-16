/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:07:45 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:07:49 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_flags(t_attrs *stuff, const char c)
{
	if (c == '-')
		stuff->flagminus = 1;
	else if (c == '+')
		stuff->flagplus = 1;
	else if (c == '#')
		stuff->flaghash = 1;
	else if (c == '0')
		stuff->flagzero = 1;
	else if (c == ' ')
		stuff->flagspace = 1;
}

void			flags(t_attrs *stuff, const char *format)
{
	while (format[stuff->i] == '-' || format[stuff->i] == '+' \
	|| format[stuff->i] == '#' || format[stuff->i] == '0' \
	|| format[stuff->i] == ' ')
	{
		set_flags(stuff, format[stuff->i]);
		stuff->i++;
	}
}

void			handle_lflags(t_attrs *stuff)
{
	if (stuff->flagspace != 0 && stuff->flagplus == 0 && stuff->f >= 0)
	{
		ft_putchar(' ');
		stuff->res++;
		stuff->width--;
	}
	if (stuff->f < 0)
		stuff->flagplus = 0;
	if (stuff->f >= 0 && (stuff->flagzero != 0 || stuff->flagminus != 0)
		&& stuff->flagplus != 0)
	{
		ft_putchar('+');
		stuff->res++;
		stuff->flagplus = 0;
		stuff->width--;
	}
	if (stuff->f < -0 && stuff->flagzero == 1)
	{
		ft_putchar('-');
		stuff->f = stuff->f * -1;
		stuff->res++;
		stuff->width--;
		stuff->flagspace = 0;
	}
	l_flags_con(stuff);
}

static void		continue_flags(t_attrs *stuff)
{
	if (stuff->x < 0)
		stuff->flagplus = 0;
	if (stuff->x >= 0 && stuff->flagplus == 1 \
		&& stuff->flagzero == 1 && stuff->precision < 0)
	{
		ft_putchar('+');
		stuff->res++;
		stuff->flagplus = 0;
		stuff->width--;
	}
	if (stuff->x < 0 && stuff->flagzero != 0 && stuff->precision < 0)
	{
		ft_putchar('-');
		stuff->res++;
		stuff->x = stuff->x * -1;
		stuff->width--;
	}
}

void			handle_flags(t_attrs *stuff, const char *format)
{
	if (stuff->flagspace != 0 && stuff->flagplus == 0 && \
		format[stuff->i] != 'f' && stuff->x >= 0 \
		&& format[stuff->i] != 'u')
	{
		ft_putchar(' ');
		stuff->res++;
		stuff->width--;
	}
	if (format[stuff->i] == 'i' || format[stuff->i] == 'd')
		continue_flags(stuff);
	else if ((format[stuff->i] == 'x' || format[stuff->i] == 'X') \
		&& stuff->flaghash == 1)
	{
		stuff->width = stuff->width - 2;
	}
	else if (format[stuff->i] == 'o' && stuff->flaghash == 1)
		stuff->width = stuff->width - 1;
}
