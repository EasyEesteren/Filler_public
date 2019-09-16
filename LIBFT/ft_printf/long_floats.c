/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   long_floats.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:11:14 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:11:16 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		no_precision(t_attrs *stuff, long double n)
{
	char ar[1000];

	ft_bzero(ar, 1000);
	while (n || stuff->len < 6)
	{
		n = n * 10;
		ar[stuff->len] = (int)n + '0';
		n = n - (int)n;
		stuff->len++;
	}
	stuff->cnt = stuff->precision;
	stuff->precision = 6;
	round_nines(ar, stuff);
	ar[6] = '\0';
	put_numl(stuff, ar);
}

static void		put_zeroes(t_attrs *stuff)
{
	long int len;

	len = 0;
	if (stuff->precision != 0)
	{
		stuff->res += ft_nbrlen(stuff->x);
		ft_putnbr(stuff->x);
		ft_putchar('.');
		stuff->res++;
		if (stuff->precision < 0)
			stuff->precision = 6;
		while (len < stuff->precision)
		{
			ft_putchar('0');
			stuff->res++;
			len++;
		}
	}
}

static void		ft_floatdec(long double n, t_attrs *stuff)
{
	char	ar[1000];

	ft_bzero(ar, 1000);
	stuff->x = (long long int)stuff->f;
	if (n == 0)
		put_zeroes(stuff);
	else if (stuff->precision <= -1)
		no_precision(stuff, n);
	else if (stuff->len < stuff->precision)
	{
		while (n || stuff->len < stuff->precision)
		{
			n = n * 10;
			ar[stuff->len] = (int)n + '0';
			n = n - (int)n;
			stuff->len++;
		}
		stuff->cnt = stuff->precision;
		if (round_nines(ar, stuff) == 0 && ar[stuff->cnt] > '5')
			ar[stuff->cnt - 1]++;
		ar[stuff->cnt] = '\0';
		put_numl(stuff, ar);
	}
}

void			handle_lfloat(t_attrs *stuff, va_list args)
{
	long double x;

	stuff->f = va_arg(args, long double);
	x = find_dec(stuff->f);
	handle_lflags(stuff);
	stuff->save = stuff->precision;
	if (stuff->precision > 0)
		stuff->width--;
	if (stuff->flagminus == 0)
		width_f(stuff);
	stuff->len = 0;
	if (stuff->f < -0 && stuff->f > -1 && stuff->flagzero == 0 \
	&& stuff->precision == 0)
	{
		ft_putchar('-');
		stuff->res++;
		stuff->flagspace = 0;
	}
	ft_floatdec(x, stuff);
	stuff->precision = stuff->save;
	if (stuff->precision == 0)
		zero_precision_f(stuff);
	if (stuff->flagminus != 0)
		width_f(stuff);
}
