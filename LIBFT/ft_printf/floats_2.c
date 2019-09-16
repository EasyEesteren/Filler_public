/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floats_2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/15 17:56:21 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/06/15 17:56:22 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_num(t_attrs *stuff, char *ar)
{
	if (stuff->flagplus != 0 && stuff->f > 0 && stuff->flagzero == 0)
		put_plus(stuff);
	if (stuff->x == 0 && stuff->f < -0)
	{
		ft_putchar('-');
		stuff->res++;
	}
	ft_putnbr(stuff->x);
	ft_putchar('.');
	ft_putstr(ar);
	stuff->res += ft_nbrlen(stuff->x) + ft_strlen(ar) + 1;
}
