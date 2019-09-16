/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointer_conv.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:11:42 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:11:46 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pointer_width(t_attrs *stuff, char *adr)
{
	stuff->width = stuff->width - (ft_strlen(adr) + 2);
	if (stuff->width > 0)
	{
		while (stuff->width > 0)
		{
			ft_putchar(' ');
			stuff->width--;
		}
	}
}

int				pointer_conv(va_list args, t_attrs *stuff)
{
	char		*adr;
	long long	i;

	i = va_arg(args, long long);
	adr = ft_itoabase(i, 16);
	if (stuff->flagminus == 0)
		pointer_width(stuff, adr);
	ft_putstr("0x");
	stuff->res += 2;
	ft_putstr(adr);
	if (stuff->flagminus != 0)
		pointer_width(stuff, adr);
	stuff->res += ft_strlen(adr);
	free(adr);
	return (0);
}
