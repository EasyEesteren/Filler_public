/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floaters.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:07:54 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:07:56 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		round_backnines(t_attrs *stuff, char *ar)
{
	while (ar[stuff->precision - 1] == '9' && stuff->precision >= 0)
	{
		ar[stuff->precision - 1] = '0';
		if (stuff->precision - 1 <= 0 && stuff->f > 0)
			stuff->x++;
		else if (stuff->precision - 1 <= 0 && stuff->f < 0)
			stuff->x--;
		stuff->precision--;
	}
	if (stuff->precision > 0)
		ar[stuff->precision - 1]++;
}

static void		roundback_fives(char *ar, t_attrs *stuff)
{
	if (ar[stuff->precision] > '5' && ar[stuff->precision - 1] == '5')
	{
		stuff->precision--;
		while (ar[stuff->precision] == '5' && \
			stuff->precision >= stuff->cnt)
			stuff->precision--;
		ar[stuff->precision]++;
	}
	else if (ar[stuff->precision] == '5')
		ar[stuff->precision - 1]++;
}

int				round_nines(char *ar, t_attrs *stuff)
{
	while (stuff->precision < stuff->len)
	{
		if (ar[stuff->precision - 1] == '9' && ar[stuff->precision] >= '5')
		{
			round_backnines(stuff, ar);
			return (1);
		}
		if (ar[stuff->precision - 1] == '5' || ar[stuff->precision] == '5')
		{
			roundback_fives(ar, stuff);
			return (1);
		}
		else if (ar[stuff->precision] > '5' && stuff->cnt > 0)
		{
			ar[stuff->precision - 1]++;
			return (1);
		}
		stuff->precision++;
	}
	return (0);
}
