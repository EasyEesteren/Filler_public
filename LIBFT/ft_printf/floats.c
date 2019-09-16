/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floats.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:08:01 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:20:46 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	no_precision(t_attrs *stuff, long double n)
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
	put_num(stuff, ar);
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
		while (len < stuff->precision)
		{
			ft_putchar('0');
			len++;
			stuff->res++;
		}
	}
}

double			find_dec(long double a)
{
	double mod;

	if (a > 0)
		mod = a - (long int)a;
	else
	{
		a = a * -1;
		mod = a - (long int)a;
	}
	return (mod);
}

static void		ft_floatdec(double n, t_attrs *stuff)
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
		round_nines(ar, stuff);
		ar[stuff->cnt] = '\0';
		put_num(stuff, ar);
	}
}

void			handle_float(t_attrs *stuff, va_list args)
{
	double x;

	stuff->f = va_arg(args, double);
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
