/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 16:00:37 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/06/06 16:00:39 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_oct_nxt(t_attrs *stuff)
{
	if (stuff->precision > 0)
		stuff->res += stuff->precision;
	if (stuff->precision != 0 && stuff->x == 0)
	{
		ft_putchar('0');
		stuff->res++;
	}
	while (stuff->precision > 0)
	{
		ft_putchar('0');
		stuff->precision--;
		stuff->width--;
	}
}

void	precision_dgt_nxt(t_attrs *stuff)
{
	if (stuff->precision > 0)
		stuff->res += stuff->precision;
	if (stuff->precision != 0 && stuff->x == 0)
	{
		ft_putchar('0');
		stuff->res++;
	}
	while (stuff->precision > 0)
	{
		ft_putchar('0');
		stuff->precision--;
		stuff->width--;
	}
}
