/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strings_chars.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:12:15 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:12:17 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstrn(char *str, int n, t_attrs *stuff)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		ft_putchar(str[i]);
		i++;
	}
	stuff->res += i;
}

static	void	place_c(va_list args, const char *format, t_attrs *stuff)
{
	if (stuff->flagminus == 0)
		width_sc(format, stuff);
	ft_putchar(va_arg(args, int));
	stuff->res += 1;
	if (stuff->flagminus != 0)
		width_sc(format, stuff);
}

int				put_sc(va_list args, const char *format, t_attrs *stuff)
{
	if (format[stuff->i] == 's')
	{
		stuff->str = va_arg(args, char *);
		if (stuff->str == NULL)
		{
			ft_putstr("(null)");
			stuff->res += 6;
			return (0);
		}
		if (stuff->flagminus == 0)
			width_sc(format, stuff);
		if (stuff->precision > -1 && ft_strlen(stuff->str) > 0)
			ft_putstrn(stuff->str, stuff->precision, stuff);
		else
		{
			ft_putstr(stuff->str);
			stuff->res += ft_strlen(stuff->str);
		}
		if (stuff->flagminus != 0)
			width_sc(format, stuff);
	}
	else if (format[stuff->i] == 'c')
		place_c(args, format, stuff);
	return (1);
}
