/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   no_specifier.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:11:30 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:11:32 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		widtholo(t_attrs *stuff, const char *format)
{
	stuff->width = stuff->width - (int)ft_strlen(&format[stuff->i]);
	if (stuff->width > 0)
		stuff->res = stuff->res + stuff->width;
	if (stuff->flagminus != 0)
	{
		ft_putchar(format[stuff->i]);
		stuff->res++;
		stuff->i++;
	}
	while (stuff->width > 0)
	{
		ft_putchar(stuff->width_c);
		stuff->width--;
	}
}

void			no_specifier(t_attrs *stuff, const char *format)
{
	if (stuff->precision < stuff->width && stuff->flagminus == 0)
		widtholo(stuff, format);
	if (stuff->flagminus != 0)
		widtholo(stuff, format);
	if (format[stuff->i])
	{
		ft_putchar(format[stuff->i]);
		stuff->res++;
	}
}
