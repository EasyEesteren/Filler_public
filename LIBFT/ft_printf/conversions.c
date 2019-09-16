/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 16:26:41 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/03 16:26:43 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_handler(t_attrs *stuff, const char *format, va_list args)
{
	if (ft_strlen(stuff->length) == 0 && (format[stuff->i] == 'x' \
	|| format[stuff->i] == 'X'))
		stuff->u_x = va_arg(args, unsigned long long);
	if (format[stuff->i] == 'x')
		hexadecimal(stuff->u_x, stuff);
	else if (format[stuff->i] == 'X')
		hexadecimal_upper(stuff->u_x, stuff);
	if (format[stuff->i] != 'X' && format[stuff->i] != 'X' \
	&& stuff->flagminus != 0)
	{
		stuff->cnt = 0;
		width_dgt_aft(stuff, format);
	}
}

void	octal_len(unsigned long long int dec, t_attrs *stuff)
{
	unsigned long long temp;

	temp = dec;
	if (temp % 8 == temp)
	{
		temp = temp + 48;
		stuff->cnt++;
	}
	else
	{
		stuff->cnt++;
		octal_len(temp / 8, stuff);
		temp = temp % 8 + 48;
	}
}

void	octal(unsigned long long int dec, t_attrs *stuff)
{
	if (dec % 8 == dec)
	{
		dec = dec + 48;
		ft_putchar(dec);
		stuff->oct_len++;
	}
	else
	{
		octal(dec / 8, stuff);
		dec = dec % 8 + 48;
		ft_putchar(dec);
		stuff->oct_len++;
	}
}

void	hexadecimal(unsigned long long int dec, t_attrs *stuff)
{
	if (dec == 0 && stuff->precision != 0)
	{
		ft_putchar('0');
		stuff->res += 1;
	}
	else if (stuff->precision != 0)
		create_hexa_low(dec, stuff);
	else
		width_dgt_ux(stuff, 0);
}

void	hexadecimal_upper(unsigned long long int dec, t_attrs *stuff)
{
	if (dec == 0 && stuff->precision != 0)
	{
		ft_putchar('0');
		stuff->res += 1;
	}
	else if (stuff->precision != 0)
		create_hexa_up(dec, stuff);
	else
		width_dgt_ux(stuff, 0);
}
