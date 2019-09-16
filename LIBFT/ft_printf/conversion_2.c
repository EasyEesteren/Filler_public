/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 15:56:29 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/06/06 15:56:33 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			place_hexa(t_attrs *stuff, char hexa[])
{
	if (stuff->flagminus == 0 || stuff->precision >= stuff->width)
	{
		if (stuff->flaghash != 0)
			stuff->res += 2;
		if (stuff->flaghash == 1 && stuff->flagzero == 1)
			ft_putstr("0x");
		if (stuff->width > stuff->precision)
			width_dgt_ux(stuff, stuff->cnt);
		if (stuff->flaghash == 1 && stuff->flagzero == 0)
			ft_putstr("0x");
		precision_dgt_ux(stuff, stuff->cnt);
	}
	while (stuff->cnt > 0)
	{
		ft_putchar(hexa[stuff->cnt]);
		stuff->cnt--;
	}
	if (stuff->flagminus != 0)
		width_dgt_ux(stuff, stuff->save);
}

void			create_hexa_low(unsigned long long int dec, t_attrs *stuff)
{
	long long int	i;
	long long int	temp;
	char			hexa[100];

	ft_bzero(hexa, 100);
	i = 1;
	while (dec != 0)
	{
		temp = dec % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hexa[i++] = temp;
		dec = dec / 16;
	}
	stuff->cnt = i - 1;
	stuff->save = stuff->cnt;
	stuff->res += stuff->cnt;
	place_hexa(stuff, hexa);
}

void			create_hexa_up(unsigned long long int dec, t_attrs *stuff)
{
	long long int	i;
	long long int	temp;
	char			hexa[100];

	ft_bzero(hexa, 100);
	i = 1;
	while (dec != 0)
	{
		temp = dec % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		hexa[i++] = temp;
		dec = dec / 16;
	}
	stuff->cnt = i - 1;
	stuff->save = stuff->cnt;
	stuff->res += stuff->cnt;
	place_hexa(stuff, hexa);
}

static	void	put_stuff(t_attrs *stuff)
{
	if (stuff->flagplus == 1)
	{
		ft_putchar('+');
		stuff->res++;
	}
	stuff->res += ft_nbrlen(stuff->x);
	ft_putnbr(stuff->x);
	if (stuff->flaghash != 0)
	{
		ft_putchar('.');
		stuff->res++;
	}
}

void			zero_precision_f(t_attrs *stuff)
{
	char			ar[1000];
	long double		n;
	int				i;

	i = 0;
	ft_bzero(ar, 1000);
	n = find_dec(stuff->f);
	while (n)
	{
		n = n * 10;
		ar[i] = (int)n + '0';
		n = n - (int)n;
		i++;
	}
	if (ar[0] >= '5' && stuff->x >= 0)
		stuff->x++;
	else if (ar[0] >= '5' && stuff->x < 0)
		stuff->x--;
	put_stuff(stuff);
}
